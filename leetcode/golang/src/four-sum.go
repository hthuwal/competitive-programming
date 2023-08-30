/* -------------------------------------------------------------------------- */
/*                     https://leetcode.com/problems/4sum/                    */
/* -------------------------------------------------------------------------- */
package main

import (
	"sort"
)

func FourSum(nums []int, target int) [][]int {
	ans := [][]int{}
	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for j := i + 1; j < len(nums); j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}

			k := j + 1
			l := len(nums) - 1
			for k < l {
				if k > j+1 && nums[k] == nums[k-1] {
					k++
					continue
				}

				if l < len(nums)-1 && nums[l] == nums[l+1] {
					l--
					continue
				}

				sum := nums[i] + nums[j] + nums[k] + nums[l]
				if sum < target {
					k++
				} else if sum > target {
					l--
				} else {
					ans = append(ans, []int{nums[i], nums[j], nums[k], nums[l]})
					k++
					l--
				}
			}
		}
	}
	return ans
}
