#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define si set<lli>
#define sit si::iterator
si v;
si h;

int find(int x1, int x2, int y1, int y2, bool hr)
{
	if(x1>=x2)
		return 0;
	if(y1>=y2)
		return 0;
	if(hr)
	{
		int mid = (x1+x2)>>1;
		sit it = v.lower_bound(mid);
		if(it == v.end() || *it < x1 )
	}
}
int main()
{
	int t;
	lli n,m,q;
	for(scanf("%d",&t);t--;)
	{
		scanf("%lld %lld %lld", &n, &m, &q);
		
	}
}