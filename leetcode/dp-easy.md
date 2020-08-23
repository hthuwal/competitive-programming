### [Top Interview Questions. Easy Collection. DP](https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/)

#### Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int num_steps[n+1];
        num_steps[0]=1;
        num_steps[1]=1;
        for(int i=2;i<=n;i++)
            num_steps[i] = num_steps[i-1]+num_steps[i-2];
        return num_steps[n];
    }
};
```
#### Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n>1)
        {
            vector<int> max_from_right(n, -1);
            max_from_right[n-1]=prices[n-1];

            for(int i=n-2;i>=0;i--)
            {
                if(prices[i]>max_from_right[i+1])
                    max_from_right[i] = prices[i];
                else
                    max_from_right[i] = max_from_right[i+1];     
            }
            int max_profit = INT_MIN;

            for(int i=0;i<n-1;i++)
            {
                int profit = max_from_right[i+1] - prices[i];
                if(profit > max_profit)
                    max_profit = profit;
            }
            return max_profit > 0? max_profit : 0;
        }
        return 0;
    }
    
};
```
##### Maximum Subarray  (Kadane's Algorithm)

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int msf = INT_MIN;
        int meh = 0;
        for(int i=0;i<n;i++)
        {
            meh = meh + nums[i];
            if(meh > msf)
                msf = meh;
            
            if(meh < 0)
                meh = 0;
        }
        return msf;
    }
};
```
##### House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        dp[0]=0;
        int prev;
        for(int i=1;i<=n;i++)
        {
            if(i == 1)
                prev = 0;
            else
                prev = dp[i-2];
            
            dp[i] = max(dp[i-1], nums[i-1]+prev);
        }
        return  dp[n];
    }
};
```

