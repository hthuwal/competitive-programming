/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/delete-and-earn               */
/* -------------------------------------------------------------------------- */
package main

func DeleteAndEarn(nums []int) int {
	max := nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] > max {
			max = nums[i]
		}
	}

	freq := make([]int, max+1)
	for i := 0; i < len(nums); i++ {
		freq[nums[i]] += 1
	}

	for i := 2; i < max+1; i++ {
		freq[i] = i*freq[i] + freq[i-2]
		if freq[i-1] > freq[i] {
			freq[i] = freq[i-1]
		}
	}

	return freq[max]
}
