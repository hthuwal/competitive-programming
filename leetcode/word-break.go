package main

import "fmt"

// TLE
func solve(s string, dict *map[string]bool) bool {
	fmt.Println("S is ", s)
	if len(s) == 0 {
		return true
	}

	ans := false
	for i := len(s) - 1; i >= 0; i-- {
		pre := s[:i+1]
		fmt.Println(pre)
		if (*dict)[pre] {
			ans = ans || solve(s[i+1:], dict)
			if ans {
				return ans
			}
		}
	}
	return false
}

func wordBreak(s string, wordDict []string) bool {
	dict := map[string]bool{}
	for _, word := range wordDict {
		dict[word] = true
	}
	return solve(s, &dict)
}

func main() {
	fmt.Println(wordBreak("harish", []string{"hari", "sh"}))
}
