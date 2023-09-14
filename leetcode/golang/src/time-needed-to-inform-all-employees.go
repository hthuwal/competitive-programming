/* -------------------------------------------------------------------------- */
/*      https://leetcode.com/problems/time-needed-to-inform-all-employees     */
/* -------------------------------------------------------------------------- */

package main

func calculateTime(e, headID int, manager, informTime []int, memory map[int]int) int {
	if e == headID {
		return 0
	}

	if t, ok := memory[e]; ok {
		return t
	} else {
		memory[e] = calculateTime(manager[e], headID, manager, informTime, memory) +
			informTime[manager[e]]
		return memory[e]
	}
}

func NumOfMinutes(n int, headID int, manager []int, informTime []int) int {
	memory := map[int]int{}
	for i := 0; i < n; i++ {
		calculateTime(i, headID, manager, informTime, memory)
	}

	ans := 0
	for _, v := range memory {
		if v > ans {
			ans = v
		}
	}
	return ans
}
