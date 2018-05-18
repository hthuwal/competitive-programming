#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int r,c,m,n,test,p;
	long int ans;
	cin>>test;
	while(test--)
	{
		ans=0;
		cin>>m>>n;
		vector<int> a;
		vector<int> b;
		for(int i=0;i<m-1;i++)
		{
			cin>>p;
			a.push_back(p);
		}
		for(int i=0;i<n-1;i++)
		{
			cin>>p;
			b.push_back(p);
		}
		sort(a.begin(),a.begin()+a.size());
		sort(b.begin(),b.begin()+b.size());
		r=1;
		c=1;
		while(!a.empty() && !b.empty())
		{	
			if(a.back()>b.back())
			{
				ans+=a.back()*r;
				a.pop_back();
				c++;
			}
			else if(a.back()<=b.back())
			{
				ans+=b.back()*c;
				b.pop_back();
				r++;
			}
		}
		while(!a.empty())
		{
			ans+=a.back()*r;
			a.pop_back();
		}
		while(!b.empty())
		{
			ans+=b.back()*c;
			b.pop_back();
		}
		cout<<ans<<"\n";
	}
}