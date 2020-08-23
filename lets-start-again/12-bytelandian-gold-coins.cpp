// https://www.spoj.com/problems/COINS/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int

map<lli, lli> hc_hash;

lli max(lli a, lli b)
{
	if(a>b)
		return a;
	return b;
}

lli solve_memoized(lli n)
{
	if (hc_hash.find(n) != hc_hash.end())
		return hc_hash[n];
	
	if (n==0)
		return 0;
	
	if (n==1)
		return 1;

	hc_hash[n] = max(n, solve_memoized(n/2) + solve_memoized(n/3) + solve_memoized(n/4));
	return hc_hash[n];
}

int main()
{
	lli n;
	cin.sync_with_stdio(false);
	while(cin>>n)
	{
		cout<<solve_memoized(n)<<"\n";
	}
}