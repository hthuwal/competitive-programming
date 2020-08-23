#include <bits/stdc++.h>
using namespace std;
int ring(vector<pair<int,int > > x)
{
	int max_outer=0;
	int index_out=-1;
	int max_inner=0;
	int index_in=-1;

	for(int i=0;i<x.size();i++)
	{
		if(x[i].first>max_inner)
		{
			max_inner=x[i].first;
			index_in=i;
		}
	}
//	cout<<max_inner<<endl;

	for(int i=0;i<x.size();i++)
	{
		if(x[i].second>max_outer && i!=index_in)
		{
			max_outer=x[i].second;
			index_out=i;
		}
	}
//	cout<<max_outer<<endl;

	if(max_inner>max_outer)
		return index_in+1;
	else 
		return -1;


}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	int t;
	cin>>t;
	while(t--)
	{
		vector<pair<int,int> > v; 
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v.push_back(make_pair(x,y));
		}
		cout<<ring(v)<<endl;
		ring(v);
	}
}