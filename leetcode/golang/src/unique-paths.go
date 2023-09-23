/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/unique-paths                 */
/* -------------------------------------------------------------------------- */

package main

func UniquePaths(m int, n int) int {
	dp := make([][]int, 1)
	dp[0] = make([]int, n)

	for i := 0; i < n; i++ {
		dp[0][i] = 1
	}

	for i := 1; i < m; i++ {
		this_row_prev_column := dp[0][0]
		for j := 1; j < n; j++ {
			dp[0][j] += this_row_prev_column

			// Shift and move upward
			this_row_prev_column = dp[0][j]
		}
	}
	return dp[0][n-1]
}
