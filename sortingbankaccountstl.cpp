#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int t,i,n;
	cin>>t;
	while(t--)
	{
		string hc[100005];
		cin>>n;
		cin.ignore();
		for(i=0;i<n;i++)
			getline(std::cin,hc[i],'\n');
		
		multiset<string>jp (hc,hc+n);
		set<string>aadi (jp.begin(),jp.end());
		set<string>::iterator it;
		for(it=aadi.begin();it!=aadi.end();it++)
		{
			cout<<*it <<jp.count(*it)<<endl;;
		}
		cout<<endl;
	}
	
}
