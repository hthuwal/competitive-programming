/* -------------------------------------------------------------------------- */
/*         https://leetcode.com/problems/student-attendance-record-ii/        */
/* -------------------------------------------------------------------------- */
package main

const M = 1000000007

func CheckRecord(n int) int {
	dp := make([][]int64, 5)
	for i := range dp {
		dp[i] = make([]int64, n)
	}

	// dp[a][i]: Number of ways to be absent on the ith day (Not allowed to be absent before that ever)
	// dp[l][i]: Number of ways to be late on the ith day (Not allowed to be absent before that ever)
	// dp[p][i]: Number of wayt to be present on the ith day (Not allowed to be absent before that ever)
	// dp[al][i]: Number of ways to be late on the ithe day (Could be absent once before)
	// dp[ap][i]: Number of ways to be present on the ith day (Could be absent once before)
	a, l, p, al, ap := 0, 1, 2, 3, 4
	dp[a][0], dp[l][0], dp[p][0], dp[al][0], dp[ap][0] = 1, 1, 1, 1, 1

	for day := 1; day < n; day++ {
		/* Not allowed to be absent before
		 *
		 * If you're absent today: You have to be late or present yesterday (without being absent before ever)
		 * If you're late today:
		 *   - You can either be present yesterday,
		 *   - or late yesterday in which case you must be
		 *     present the day before that. (without being absent before ever)
		 * If you're present today:
		 *   - You can either be present yesterday
		 *   - or late yesterday. (without being absent before ever)
		 */
		dp[a][day] = dp[l][day-1] + dp[p][day-1]
		dp[l][day] = dp[p][day-1]
		if day >= 2 {
			dp[l][day] += dp[p][day-2]
		} else {
			dp[l][day] += dp[l][day]
		}
		dp[p][day] = dp[l][day-1] + dp[p][day-1]

		/*
		 * If you can be absent before
		 *
		 * You can't be absent today.
		 * If you're late today:
		 *  - You can be present yesterday (with possiblity of being absent before)
		 *  - You can be absent yesterday
		 *  - You can be late yesterday (with possibility of being absent before) in which case you must either be
		 * present the day before or absent the day before. If you're present today:
		 *  - You can be present yesterday (with possiblity of being absent before)
		 *  - You can be absent yesterday
		 *  - You can be late yesterday (with possiblity of being absent before)
		 */
		dp[al][day] = dp[ap][day-1] + dp[a][day-1]
		if day >= 2 {
			dp[al][day] += dp[ap][day-2] + dp[a][day-2]
		} else {
			dp[al][day] += 1
		}
		dp[ap][day] = dp[al][day-1] + dp[ap][day-1] + dp[a][day-1]

		for j := range dp {
			if dp[j][day] >= M {
				dp[j][day] = dp[j][day] % M
			}
		}
	}

	return int((dp[a][n-1] + dp[al][n-1] + dp[ap][n-1]) % M)
}
