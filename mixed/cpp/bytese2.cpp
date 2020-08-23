#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		set<pair<int,int> > hc;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			hc.insert(make_pair(a,1));
			hc.insert(make_pair(b,-1));
		}
		int count=0;
		int ans=0;
		for(int i=0;i<2*n;i++)
		{
			pair<int,int> temp = *(hc.begin());
			hc.erase(hc.begin());
			count = count + temp.second;
			if(count>ans)
				ans=count;
		}
		cout<<ans<<"\n";
	}

}