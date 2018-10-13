### [Jump Game](https://leetcode.com/problems/jump-game/)

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

```cpp
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool dp[n+1];
        memset(dp, false, sizeof(dp));
        dp[0]=true;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=nums[i];j++)
            {
                if(i+j<n)
                    dp[i+j] |= dp[i];
            }
        }
      
        return dp[n-1];
    }
};
```