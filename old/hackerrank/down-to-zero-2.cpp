/**
 * https://www.hackerrank.com/challenges/down-to-zero-ii/problem
 *
 */
#include <bits/stdc++.h>
using namespace std;
int dp[1000005] = {0};

void preprocess(int n)
{
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n;i++)
        dp[i] = INT_MAX;
    for(int i=1;i<=n;i++)
    {
        if(i+1 <= n)
           dp[i+1] = min(dp[i+1], dp[i]+1);
        for(int j=2;j<=i and j*i <=n; j++)
            dp[i*j] = min(dp[i*j], dp[i]+1);
    }
}

int main()
{
    vector<int> q;
    int l = 0;
    int t, a;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        q.push_back(a);
        if(a>l)
            l = a;
    }
    preprocess(l);
    for(int i=0;i<t;i++)
        cout<<dp[q[i]]<<"\n";
}
