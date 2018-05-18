#include <bits/stdc++.h>
#define vvi vector<vector<pair<long long int,long long int> > >
#define vi vector<pair<long long int,long long int> >
using namespace std;
void dp(vvi a)
{
	vector<vector<long long int> > ans(a.size(),vector<long long int> (a[0].size(),0));
   	long long int n=a.size();
	long long int m=a[0].size();
	for(long long int i=0;i<n;i++)
	{
		for(long long int j=0;j<m;j++)
		{
			if(j!=0)
			{
				a[i][j].first+=a[i][j-1].first;
			}
			if(i!=0)
			{
				a[i][j].second+=a[i-1][j].second;
			}
		}
	}
	for(long long int i=0;i<a.size();i++)
	{
		for(long long int j=0;j<a[0].size();j++)
		{
			long long int ans1 = (i>=1?ans[i-1][j]:0)+a[i][j].first;
			long long int ans2 = (j>=1?ans[i][j-1]:0)+a[i][j].second;
			ans[i][j]=max(ans1,ans2);
		}
	}
	
	cout<<ans[a.size()-1][a[0].size()-1]<<endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	while(1)
	{
		long long int n,m;
		cin>>n>>m;
		if(n==0 && m==0)
			break;
		vvi terrain(n,vi(m,make_pair(0,0)));
		for(long long int i=0;i<n;i++)
			for(long long int j=0;j<m;j++)
			{
				cin>>terrain[i][j].first;
			}

		for(long long int i=0;i<n;i++)
			for(long long int j=0;j<m;j++)
			{
				cin>>terrain[i][j].second;
			}

		dp(terrain);
	}
}