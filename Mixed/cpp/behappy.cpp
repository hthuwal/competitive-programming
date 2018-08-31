#include <iostream>
#include <cstdio>
using namespace std;

long long int ans(int a[],int b[],int n,int m)
{
	long long int dp[m+2][n+2]={0};
	for(int i=0;i<=n;i++)
	{
		if(i>=a[1] && i<=b[1])//if no. of gift available 'i' within the range then give all the gifts
		{
			dp[1][i]=1;
		}
		else
			dp[1][i]=0;
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(a[i]>j)
				dp[i][j]=0;
			else
			{
				for(int k=a[i];k<=b[i];k++)
				{
                    if(k<=j)
                        dp[i][j]+=dp[i-1][j-k];

				}
			}
		}
	}
	return dp[m][n];
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int a[25],b[25],n,m;
	while(1)
	{
		cin>>m;
		cin>>n;
		if(n==0 && m==0)
			break;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i]>>b[i];
		}
		cout<<ans(a,b,n,m)<<"\n";
	}
}
