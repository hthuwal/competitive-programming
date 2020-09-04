package main

import "fmt"

/*
 * Link to Problem: https://leetcode.com/problems/insert-interval
 */

func doOverlap(a []int, b []int) bool {
	// Start of b lies within a
	if b[0] >= a[0] && b[0] <= a[1] {
		return true
	}
	// End of b lies within a
	if b[1] >= a[0] && b[0] <= a[1] {
		return true
	}
	// a completely lies inside b
	if b[0] < a[0] && b[1] > a[1] {
		return true
	}
	return false
}

func findOverLappingIntervals(intervals [][]int, newInterval []int) []int {
	oli := []int{}
	for i, interval := range intervals {
		if doOverlap(interval, newInterval) {
			oli = append(oli, i)
		}
	}
	return oli
}

func insert(intervals [][]int, newInterval []int) [][]int {
	if len(intervals) == 0 {
		return append(intervals, newInterval)
	}

	ans := make([][]int, 0, len(intervals)+1)
	oli := findOverLappingIntervals(intervals, newInterval)

	// If no interval overlaps
	if len(oli) == 0 {
		// newInterval should be at the beginning
		if newInterval[1] < intervals[0][0] {
			ans = append(ans, newInterval)
			ans = append(ans, intervals...)
			return ans
		}

		// Find the place where it should be present
		ti := 0
		for i := len(intervals) - 1; i >= 0; i-- {
			if intervals[i][1] < newInterval[0] {
				ti = i
				break
			}
		}
		ans = append(ans, intervals[0:ti+1]...)
		ans = append(ans, newInterval)
		ans = append(ans, intervals[ti+1:]...)
		return ans
	}

	// Some consecutive interval Overlaps.
	// Create single merged interval
	ifo, ilo := oli[0], oli[len(oli)-1]
	first, last := intervals[ifo], intervals[ilo]

	if first[0] < newInterval[0] {
		newInterval[0] = first[0]
	}
	if last[1] > newInterval[1] {
		newInterval[1] = last[1]
	}

	ans = append(ans, intervals[0:ifo]...)
	ans = append(ans, newInterval)
	ans = append(ans, intervals[ilo+1:]...)
	return ans
}

func main() {
	intervals := [][]int{
		{1, 2},
		{3, 5},
		{6, 7},
		{8, 10},
		{12, 16},
	}
	fmt.Println(insert(intervals, []int{4, 8}))
}
