/* -------------------------------------------------------------------------- */
/*                     https://leetcode.com/problems/3sum/                    */
/* -------------------------------------------------------------------------- */

package main

import (
	"fmt"
	"sort"
)

func twoPointerSum(nums []int, target int, ans *[][]int) {
	i := 0
	j := len(nums) - 1
	for i < j {
		// Ignore this num if its same as previous number to avoid duplicates
		if i > 0 && nums[i] == nums[i-1] {
			i++
			continue
		}

		// Ignore this num if its same as previous number to avoid duplicates
		if j < len(nums)-1 && nums[j] == nums[j+1] {
			j--
			continue
		}

		if nums[i]+nums[j] < target {
			i++
		} else if nums[i]+nums[j] > target {
			j--
		} else {
			*ans = append(*ans, []int{nums[i], nums[j], -target})
			i++
			j--
		}
	}
}

func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	ans := [][]int{}
	for i := range nums {
		// Ignore this num if its same as previous number to avoid duplicates
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		twoPointerSum(nums[i+1:], -nums[i], &ans)
	}
	return ans
}

func run() {
	fmt.Println(threeSum([]int{-1, 0, 1, 2, -1, -4}))
}
