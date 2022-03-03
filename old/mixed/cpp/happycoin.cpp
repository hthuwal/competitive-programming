#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif 
	int t,n;
	cin>>t;
	string hc;
	while(t--)
	{
		cin>>n;
		int flag=0;
		int ans;
		while(n--)
		{
			cin>>hc;
			if(flag==0)
			{
				if(hc=="lxh")
					ans=1;
				else 
					ans=0;
				flag=1;
			}
			else
			{
				if(hc=="lxh")	
					ans = ans ^ 1;
				else
					ans = ans ^ 0;
			}

		}
		if(ans==1)
			cout<<"lxh"<<"\n";
		else 
			cout<<"hhb"<<"\n";
	}
}