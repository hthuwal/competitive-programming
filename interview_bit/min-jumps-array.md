## [Min Jumps Array](https://www.interviewbit.com/problems/min-jumps-array/)

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

### O(n) 
```cpp 
int Solution::jump(vector<int> &arr) {
    
    int n = arr.size();
    int dp[n];
    
    for(int i=0;i<n;i++) dp[i] = -1;
    
    dp[0] = 0;
    int reach = 0;
    
    for(int i=0;i<n;i++)
    {
        if(reach < i)
            return -1;
        for(int k = reach + 1; k<n and k<=i+arr[i]; k++)
            dp[k] = dp[i] + 1;
        reach = max(reach, i + arr[i]);
    }
    return dp[n-1];
}
```