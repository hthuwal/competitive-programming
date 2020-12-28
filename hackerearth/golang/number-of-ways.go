/**
 * https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/rook-path-142e55ee/
 **/
package main

import "fmt"

type tripletNumberOfWays struct {
	numW, sumL, sumU int64
}

var mod int64

func solveNumberOfWays() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	grid := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s", &grid[i])
	}

	dp := make([][]tripletNumberOfWays, n)
	for i := range dp {
		dp[i] = make([]tripletNumberOfWays, m)
	}

	for i := range dp {
		for j := range dp[i] {
			if i == 0 && j == 0 {
				dp[i][j] = tripletNumberOfWays{1, 1, 1}
				continue
			}

			if grid[i][j] == '*' {
				dp[i][j] = tripletNumberOfWays{0, 0, 0}
				continue
			}

			sumL := int64(0)
			sumU := int64(0)

			if j != 0 {
				sumL = dp[i][j-1].sumL
			}

			if i != 0 {
				sumU = dp[i-1][j].sumU
			}
			numW := (sumL + sumU) % mod
			dp[i][j] = tripletNumberOfWays{
				numW,
				(sumL + numW) % mod,
				(sumU + numW) % mod}
		}
	}
	fmt.Println(dp[n-1][m-1].numW)
}

func numberOfWays() {
	var t int
	mod = 1000000007
	fmt.Scanf("%d", &t)
	for t > 0 {
		solveNumberOfWays()
		t--
	}
}
