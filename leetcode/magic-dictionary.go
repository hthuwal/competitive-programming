package main

import "fmt"

type pathState struct {
	node *MagicDictionary
	i    int  // index Of Search String
	ra   bool // replaceAllowed
}

// MagicDictionary ...
type MagicDictionary struct {
	children       map[byte]*MagicDictionary
	wordEndingHere bool
}

// Constructor ...
func Constructor() MagicDictionary {
	m := MagicDictionary{}
	m.children = make(map[byte]*MagicDictionary)
	return m
}

func (m *MagicDictionary) addWord(str string, i int) {
	if i == len(str) {
		m.wordEndingHere = true
		return
	}
	children := m.children
	if _, isPresent := children[str[i]]; !isPresent {
		m := Constructor()
		children[str[i]] = &m
	}
	children[str[i]].addWord(str, i+1)
}

// BuildDict ...
func (m *MagicDictionary) BuildDict(dictionary []string) {
	for _, str := range dictionary {
		m.addWord(str, 0)
	}
}

// Search ...
func (m *MagicDictionary) Search(searchWord string) bool {
	q := make([]pathState, 0, len(searchWord)*2)
	q = append(q, pathState{m, 0, true})

	front := pathState{}
	ans := false
	for len(q) != 0 {

		front, q = q[0], q[1:] // pop the front of the queue

		i := front.i
		replaceAllowed := front.ra
		node := front.node

		// searchWord has finished
		if i == len(searchWord) {
			// This is not an exact match
			if !replaceAllowed && node.wordEndingHere {
				ans = true
				break
			}
		} else { // continue searching
			if replaceAllowed { // replace allowed we can follow any path
				for char, childNode := range node.children {
					if char == searchWord[i] {
						q = append(q, pathState{childNode, i + 1, true})
					} else {
						q = append(q, pathState{childNode, i + 1, false})
					}
				}
			} else { // replace not allowed only path is matched path
				if childNode, ok := node.children[searchWord[i]]; ok {
					q = append(q, pathState{childNode, i + 1, false})
				}
			}
		}
	}
	return ans
}

func main() {
	obj := Constructor()
	words := []string{"a", "b", "ab"}
	obj.BuildDict(words)
	fmt.Println(obj.Search("b"))
}
