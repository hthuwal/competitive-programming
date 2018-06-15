#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli toys[100005];
lli table[100005];

lli dp(int n)
{
	if(n==1)
		return toys[0];
	if(n==2)
		return toys[0]+toys[1];
	if(n==3)
		return toys[0]+toys[1]+toys[2];

	table[n-1]=toys[n-1];
	table[n-2]=toys[n-2] + toys[n-1];
	table[n-3]=toys[n-3] + toys[n-2] + toys[n-1];

	lli a1,a2,a3;
	for(int i=n-4; i>=0; i--)
	{
		a1 = toys[i];
		a2 = a1 + toys[i+1];
		a3 = a2 + toys[i+2];

		a1 = i+2<n ? table[i+2] + a1: a1;
		a2 = i+4<n ? table[i+4] + a2 : a2;
		a3 = i+6<n ? table[i+6] + a3: a3;

		table[i] = max(a1, max(a2, a3));
	}
	return table[0];
}

// Gave TLE
lli recursive(int i, int n)
{
	lli a1=0,a2=0,a3=0;
	if(i<=n-1)
		a1 = recursive(i+2, n) + toys[i];
	if(i<=n-2)
		a2 = recursive(i+4, n) + toys[i]+toys[i+1];
	if(i<=n-3)
		a3 = recursive(i+6, n) + toys[i]+toys[i+1]+toys[i+2];

	return max(a1,max(a2,a3));
}

int main()
{
	int t, n;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%lld", &toys[i]);
		// printf("%lld\n", recursive(0, n));
		printf("%lld\n", dp(n));
	}
}