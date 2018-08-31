#include <bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int t,n,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==0)
			cout<<0<<"\n";
		else
		{
			n=n-1;
			x=n/3;
			cout<<(x*(x+1)*3)/2 + (n%3)*(x+1)<<"\n";
		}
	}
}