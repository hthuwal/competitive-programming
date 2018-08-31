#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif 
	long long int a[11000],x;
	long long int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int k=0;
		f(i,n)
		{
			cin>>a[i];
		}
		k=n;
		long long int sum = 0;
		x = k-1;
		for(long long int i=k-1;i>=0;i--)
		{
			sum+=(a[i]*x);
		//	cout<<x<<" ";
			x-=2;
		}

		cout<<sum<<"\n";
	}
}