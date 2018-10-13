### [Longest Increasing Subsequence]()

Given an unsorted array of integers, find the length of longest increasing subsequence.

#### O(n<sup>2</sup>) solution

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        int dp[n];
        dp[0]=1;
        
        int ans = 1;
        for(int i=1;i<n;i++)
        {
            dp[i]=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] and dp[j] > dp[i])
                    dp[i] = dp[j];
            }
            dp[i] += 1;
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};
```

#### TODO O(n log(n)) solution