#include <bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
}
int lcs(int a[],int b[],int ac,int bc)
{
	vector< vector<int> > dp(ac+1,vector<int>(bc+1,0)); 

	for(int i=0;i<=ac;i++)
	{
		for(int j=0;j<=bc;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[ac][bc];
}
void print(int a[],int x)
{
	for(int i=0;i<x;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif 
	int t,n;
	cin>>t;
	while(t--)
	{
		int a[2100],b[2100];
		int ac=1;
		int bc=1;
		while(1)
		{
			cin>>a[ac];
			if(a[ac]!=0)
			{
				ac++;
			}
			else 
				break;
		}
		int max=0;
		while(1)
		{
			bc=1;
			cin>>b[bc];
			if(b[bc]==0)
				break;
			else
			{
				bc++;
				while(1)
				{
					cin>>b[bc];
					if(b[bc]!=0)
					{
						bc++;
					}
					else 
						break;
				}
			}
			int x = lcs(a,b,ac-1,bc-1);
			if(x>max)
				max=x;
		}
		cout<<max<<"\n";
	}
}