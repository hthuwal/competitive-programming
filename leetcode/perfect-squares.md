### [Perfect Squares](https://leetcode.com/problems/perfect-squares/description/)

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

#### DP solution. 

Time: O(n*sqrt(n)), Space:O(n)

```cpp
class Solution {
public:
    int numSquares(int n) {

        int dp[n+1] = {0};
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i] = INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                if(i>=j*j)
                    dp[i] = min(dp[i-j*j]+1, dp[i]);
                else
                    break;
            }
        }
        return dp[n];
    }
};
```