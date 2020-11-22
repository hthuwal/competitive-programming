package main

import (
	"fmt"
	"strings"
)

type pair struct {
	word  string
	count int
}

func extractPattern(sentence string) []pair {
	pattern := make([]pair, 0)
	prev := ""
	for _, word := range strings.Split(sentence, " ") {
		if word != prev {
			pattern = append(pattern, pair{word, 1})
			prev = word
		} else {
			pattern[len(pattern)-1].count++
		}
	}
	return pattern
}

func wordPattern(pattern string, s string) bool {
	sentPattern := extractPattern(s)
	lr := make(map[byte]string)
	rl := make(map[string]byte)

	pi := 0
	for _, wordDetail := range sentPattern {
		if pi+wordDetail.count > len(pattern) {
			return false
		}

		char := pattern[pi]
		for j := pi + 1; j < pi+wordDetail.count; j++ {
			if pattern[j] != char {
				return false
			}
		}

		if word, ok := lr[char]; !ok {
			lr[char] = wordDetail.word
		} else if word != wordDetail.word {
			return false
		}

		if c, ok := rl[wordDetail.word]; !ok {
			rl[wordDetail.word] = char
		} else if c != char {
			return false
		}

		pi += wordDetail.count
	}

	if pi != len(pattern) {
		return false
	}
	return true
}

func main() {
	fmt.Println(wordPattern("abb", "dog cat cat dog"))
	// fmt.Println("abc", "dog cat dogs")
}
