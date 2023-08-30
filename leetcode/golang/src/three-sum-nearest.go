/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/3sum-closest                 */
/* -------------------------------------------------------------------------- */

package main

import (
	"sort"
)

func Abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func ThreeSumClosest(nums []int, target int) int {
	sort.Ints(nums)

	closest := nums[0] + nums[1] + nums[2]
	for k := range nums {
		i := k + 1
		j := len(nums) - 1
		for i < j {
			cur_sum := nums[i] + nums[j] + nums[k]
			if Abs(cur_sum-target) < Abs(closest-target) {
				closest = cur_sum
			}

			if cur_sum < target {
				i++
			} else if cur_sum > target {
				j--
			} else {
				return cur_sum
			}
		}
	}
	return closest
}
