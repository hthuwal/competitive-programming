### [Jump Game  2](https://leetcode.com/problems/jump-game-ii/)

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

### O(n<sup>2</sup>) DP. TLE

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        
        for(int i=0;i<n; i++) dp[i] = INT_MAX;
        dp[0] = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=1;j<=nums[i] and i+j<n; j++)
            {
                dp[i+j] = min(dp[i+j], dp[i]+1);
            }
        }
        return dp[n-1];
    }
};
```

### O(n) Solution

- O(n) because every element is updated only once.

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        
        for(int i=0;i<n; i++) dp[i] = -1;
        
        dp[0] = 0; // minimum jump to reach start is 0
        int reach = 0; // initially the reach is zero

        for(int i=0; i<n; i++)
        {
            // updated everyone beyond current reach that I can reach from i
            for(int k=reach + 1; k<n and k<=i+nums[i]; k++)
                dp[k] = dp[i]+1;

            // update the current reach
            reach = max(reach, i+nums[i]);
        }
        return dp[n-1];
    }
};
```
