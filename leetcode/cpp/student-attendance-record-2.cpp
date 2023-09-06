/* -------------------------------------------------------------------------- */
/*         https://leetcode.com/problems/student-attendance-record-ii/        */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

int checkRecord(int n) {
    auto dp = vector<vector<long>>(5, vector<long>(n, 0));

    int a = 0;   // dp[a][i]: Number of ways to be absent on the ith day (Not allowed to be absent before that ever)
    int l = 1;   // dp[l][i]: Number of ways to be late on the ith day (Not allowed to be absent before that ever)
    int p = 2;   // dp[p][i]: Number of wayt to be present on the ith day (Not allowed to be absent before that ever)
    int al = 3;  // dp[al][i]: Number of ways to be late on the ithe day (Could be absent once before)
    int ap = 4;  // dp[ap][i]: Number of ways to be present on the ith day (Could be absent once before)

    dp[a][0] = 1;
    dp[l][0] = 1;
    dp[p][0] = 1;
    dp[al][0] = 1;
    dp[ap][0] = 1;

    for (int day = 1; day < n; day++) {
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

        dp[a][day] = dp[l][day - 1] + dp[p][day - 1];
        dp[l][day] = dp[p][day - 1] + (day >= 2 ? dp[p][day - 2] : 1);
        dp[p][day] = dp[p][day - 1] + dp[l][day - 1];

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
        dp[al][day] = dp[ap][day - 1] + dp[a][day - 1] + (day >= 2 ? dp[ap][day - 2] + dp[a][day - 2] : 1);
        dp[ap][day] = dp[ap][day - 1] + dp[al][day - 1] + dp[a][day - 1];

        for (int i = 0; i < 5; i++) {
            dp[i][day] = dp[i][day] % 1000000007;
        }
    }

    return (dp[a][n - 1] + dp[al][n - 1] + dp[ap][n - 1]) % 1000000007;
}

int main() { std::cout << checkRecord(5) << "\n"; }