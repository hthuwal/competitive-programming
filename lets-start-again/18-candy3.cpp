// https://www.spoj.com/problems/CANDY3/

#include<bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
	lli t;
	cin>>t;
	cin.sync_with_stdio(false);

	while(t--)
	{
		lli n, x, sum;
		sum = 0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			sum = (sum + x % n ) % n;
		}
		if(sum % n == 0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}