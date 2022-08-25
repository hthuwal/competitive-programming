#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int increment(int& k) {
        if (k != INT_MAX) {
            return k + 1;
        }
        return k;
    }

    /* -------------- https://leetcode.com/problems/coin-change-2/ -------------- */
    /* ---------- Total number of combinations that make up the amount ---------- */
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[n + 1][amount + 1];

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= amount; j++) {
            dp[0][j] = 0;
        }

        int coin;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                coin = coins[i - 1];

                dp[i][j] = dp[i - 1][j];
                if (j >= coin) {
                    dp[i][j] += dp[i][j - coin];
                }
            }
        }
        return dp[n][amount];
    }

    /* --------------- https://leetcode.com/problems/coin-change/ --------------- */
    /* --------------- Minimum Number of coins to reach the amount -------------- */
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        int dp[n + 1][amount + 1];

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= amount; j++) {
            dp[0][j] = INT_MAX;
        }

        int coin;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                coin = coins[i - 1];

                dp[i][j] = dp[i - 1][j];
                if (j >= coin) {
                    dp[i][j] = min(increment(dp[i][j - coin]), dp[i][j]);
                }
            }
        }

        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};

int main() {
    srand(42);
    vector<int> coins;
    for (int i = 0; i < 12; i++) {
        coins.push_back(rand() % 30 + 1);
    }
    int amount = rand() % 100 + 1;
    cout << Solution().coinChange(coins, amount) << "\n";
    cout << Solution().change(amount, coins);
}