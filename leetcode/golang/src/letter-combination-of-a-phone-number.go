/* -------------------------------------------------------------------------- */
/*    https://leetcode.com/problems/letter-combinations-of-a-phone-number/    */
/* -------------------------------------------------------------------------- */
package main

var chars = map[byte]string{
	'2': "abc",
	'3': "def",
	'4': "ghi",
	'5': "jkl",
	'6': "mno",
	'7': "pqrs",
	'8': "tuv",
	'9': "wxyz",
}

func solve(digits string, i int, cand_so_far string, ans *[]string) {
	if i == len(digits) {
		if cand_so_far != "" {
			*ans = append(*ans, cand_so_far)
		}
		return
	}

	n := digits[i]
	for _, c := range chars[n] {
		solve(digits, i+1, cand_so_far+string(c), ans)
	}
}

func LetterCombinations(digits string) []string {
	ans := []string{}
	solve(digits, 0, "", &ans)
	return ans
}
