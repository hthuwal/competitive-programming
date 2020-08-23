#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	int j,t,n,s,e,ans;
	cin>>t;
	while(t--)
	{
		vector< pair<int,int> > list;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s>>e;
			list.push_back(make_pair(e,s));
		}
		sort(list.begin(),list.begin()+list.size());
		ans=1;
		j=0;
		for(int i=1;i<n;i++)
		{
			if(list[i].second>=list[j].first)
			{
				ans++;
				j=i;
			}
		}
		cout<<ans<<"\n";
	}
}