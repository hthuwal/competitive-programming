/**
 * https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/alice-and-customer-satisfaction-b6dc3745/
 **/
package main

import (
	"sort"
)

type tuple struct {
	first  int64
	second int64
}

func isValid(ranges []tuple, rate int64) bool {
	for _, pair := range ranges {
		if pair.first*rate < pair.second {
			return false
		}
	}
	return true
}

func solve(ranges []tuple, l, h int64) int64 {
	for l != h {
		m := l + (h-l)/2
		if isValid(ranges, m) {
			h = m
		} else {
			l = m + 1
		}
	}
	return l
}

func solveTestCase() {
	var n int64
	scanf("%d\n", &n)

	ranges := make([]tuple, n)
	for i := int64(0); i < n; i++ {
		scanf("%d %d %d\n", &(ranges[i].first), &(ranges[i].first), &(ranges[i].second))
	}

	sort.Slice(ranges, func(i, j int) bool {
		return ranges[i].first < ranges[j].first
	})

	for i := int64(1); i < n; i++ {
		ranges[i].second += ranges[i-1].second
	}

	printf("%d\n", solve(ranges, 1, ranges[len(ranges)-1].second+1))
}

func customerSatisfaction() {
	var t int
	scanf("%d\n", &t)
	for ; t > 0; t-- {
		solveTestCase()
	}
}
