#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int ans,n,c[110000],p[110000];
	while(1)
	{
		ans=0;
		cin>>n;
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			cin>>c[i];
		for(int i=0;i<n;i++)
			cin>>p[i];
		sort(c,c+n);
		sort(p,p+n);
		for(int i=0;i<n;i++)
		{
			ans+=(c[i]*p[n-i-1]);
		}
		cout<<ans<<"\n";
	}
}