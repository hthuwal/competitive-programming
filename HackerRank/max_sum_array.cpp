/*
https://www.hackerrank.com/challenges/max-array-sum/problem

Given an array of integers, find the subset of non-adjacent elements with the maximum sum. 
Calculate the sum of that subset.
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int maxSubsetSum(int arr[], int n) {
    int dp[n+5]={0};
    
    dp[0]=0; // array of zero length => ans is 0
    dp[1] = max(dp[0], arr[0]); // array of one length => ans is either max(0, the one element)
    
    for(int i=2;i<=n;i++)
        dp[i] = max(dp[i-1], dp[i-2]+arr[i-1]);
    // ans_upto_i-1th_ele = max(don'take last, take last)
    return dp[n];
}


int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n;i++)
        scanf("%d",&arr[i]);
    printf("%d", maxSubsetSum(arr, n));
}
