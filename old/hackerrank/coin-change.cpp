#include <bits/stdc++.h>
using namespace std;

long long int count(long long int n, vector<long long int> &coins)
{
    long long int m = coins.size();
    long long int dp[n+1][m];
    
    for(long long int i=0; i<m; i++)
        dp[0][i] = 1;

    for(long long int i=1; i<=n; i++)
    {    
        for(long long int j=0;j<m;j++)
        {
            dp[i][j] = (i >= coins[j]? dp[i-coins[j]][j]: 0);
            dp[i][j] += (j>=1? dp[i][j-1]: 0);
        }
    }
  
    return dp[n][m-1];
}
int main()
{
    long long int n,m,t;
    scanf("%lld %lld",&n,&m);
    vector<long long int> coins;
    for(long long int i=0;i<m;i++)
    {
        scanf("%lld", &t);
        coins.push_back(t);
    }
    printf("%lld\n", count(n, coins));
}