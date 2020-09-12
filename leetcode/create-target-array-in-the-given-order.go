/*
 * Problem: https://leetcode.com/problems/create-target-array-in-the-given-order/
 */

package main

func createTargetArray(nums []int, index []int) []int {
	ans := make([]int, len(nums))
	for i, t := range index {
		copy(ans[t+1:], ans[t:])
		ans[t] = nums[i]
	}
	return ans
}
