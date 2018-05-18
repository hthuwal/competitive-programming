#include <bits/stdc++.h>
using namespace std;


int dp[101][101][2];

int ans(int l, int k, int prev)
{
	if(l==0 && k==0)
		return 1;
	else if(l==0)
		return 0;
	else 
	{
		if (dp[l][k][prev] != -1)
			return dp[l][k][prev];
		if(prev == 0)
		{
			dp[l][k][prev] = ans(l-1, k, 0) + ans(l-1, k, 1);
			return dp[l][k][prev];
		}
		if(k==0){
			dp[l][k][prev] = ans(l-1, k, 0);	
			return dp[l][k][prev];
		}
		dp[l][k][prev] = ans(l-1, k, 0) + ans(l-1, k-1, 1);
		return dp[l][k][prev];
	}
}

int main()
{
	memset(dp,-1, sizeof(dp));
	int t,k,n,m;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>k>>n>>m;
		cout<<k<<" "<<ans(n,m,0)<<"\n";
	}
}