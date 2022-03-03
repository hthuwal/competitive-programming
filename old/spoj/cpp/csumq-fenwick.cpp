/**
 * https://www.spoj.com/problems/CSUMQ/
 *
 * No Updates, Only Range Sum
 *
 * Online query porcessing, Fenwick Tree
 *
 * O(q * log(n))
 */

#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define lli long long int

lli bit[N];
int n;

void update(int x, int v)
{
	for(;x<=n;x+=(x&-x))
		bit[x] += v;
}

lli getsum(int i)
{
	lli sum=0;
	for(;i>=1; i-=(i&-i))
		sum += bit[i];
	return sum;
}

int main()
{
	int a, b, c, x;
	ios::sync_with_stdio(false);

	cin>>n;
	memset(bit, 0, sizeof(bit));
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		update(i, x);
	}

	cin>>c;
	while(c--)
	{
		cin>>a>>b;
		if(a==0)
			cout<<getsum(b+1)<<"\n";
		else
			cout<<getsum(b+1)-getsum(a)<<"\n";
	}
}