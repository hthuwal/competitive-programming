#include <bits/stdc++.h>
using namespace std;

int dp(pair<int,int> rect[],int i,pair<int,int> ans,int n)
{
	if(i==0)
	{
		int x = dp(rect,i+1,make_pair(ans.first+rect[i].first,rect[i].second),n);
		int y = dp(rect,i+1,make_pair(ans.first+rect[i].second,rect[i].first),n);
		return x>y?x:y;	
	}
	else if(i<n-1)
	{
		int x = dp(rect,i+1,make_pair(ans.first+rect[i].first+abs(rect[i].second - ans.second),rect[i].second),n);
		int y = dp(rect,i+1,make_pair(ans.first+rect[i].second+abs(rect[i].first - ans.second),rect[i].first),n);
		return x>y?x:y;
	}
	else
	{
		int x = ans.first+rect[i].first+abs(rect[i].second - ans.second);
		int y = ans.first+rect[i].second+abs(rect[i].first - ans.second);
		return x>y?x:y;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	pair<int,int> rect[n];
	for(int i=0;i<n;i++)
	{
		cin>>rect[i].first>>rect[i].second;
	}
	cout<<dp(rect,0,make_pair(0,0),n);
}
	