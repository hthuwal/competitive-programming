### [Unique Paths](https://leetcode.com/problems/unique-paths/)

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

## Solution

### 2018: O(mxn) time and space

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0; i<n; i++)
            dp[0][i] = 1;
        for(int i=1; i<m; i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j!=0)
                    dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
```

### Solution: O(mxn) time, O(n) space

- Bottom Up (This implementation is). Doesn't have to be

#### Golang 

```go
func uniquePaths(m int, n int) int {
    dp := make([]int, n)
    for i := 0; i< n; i++ {
        dp[i] = 1;
    }
    for i :=0; i < m-1; i++ {
        for j:=n-2; j >=0; j-- {
            dp[j] = dp[j] + dp[j+1]
        }
    }
    return dp[0]
}
```

#### C++

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n];
        for (int i=0;i<n;i++)
            dp[i] = 1;
        
        for (int i=0;i<m-1;i++)
            for(int j=n-2;j>=0;j--)
                dp[j] = dp[j] + dp[j+1];
        
        return dp[0];
    }
};
```