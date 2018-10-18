/**
 * https://www.spoj.com/problems/HORRIBLE/
 *
 * Segment tree with lazy propogation
 */

#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define lli long long int
lli tree[3*N];
lli lazy[3*N];

void update(lli ti, lli as, lli ae, lli ts, lli te, lli v)
{
	lli left = 2*ti+1;
	lli right = 2*ti+2;
	lli mid = as + ((ae-as)>>1);
	
	if(lazy[ti] != 0)
	{
		tree[ti] += (ae-as+1)*lazy[ti];

		if(as != ae)
		{
			lazy[left] += lazy[ti];
			lazy[right] += lazy[ti];
		}
		lazy[ti] = 0;
	}

	if(ts > ae or te < as)
		return;


	if(as >= ts and ae <= te)
	{
		tree[ti] += (ae-as+1)*v;
		if(as != ae)
		{
			lazy[left] += v;
			lazy[right] += v;
		}
	}
	else
	{
		update(left, as, mid, ts, te, v);
		update(right, mid+1, ae, ts, te, v);

		tree[ti] = (tree[left]+tree[right]);
	}
}

lli getsum(lli ti, lli as, lli ae, lli ts, lli te)
{
	lli left = 2*ti+1;
	lli right = 2*ti+2;
	lli mid = as + ((ae-as)>>1);
	
	if(lazy[ti] != 0)
	{
		tree[ti] += (ae-as+1)*lazy[ti];

		if(as != ae)
		{
			lazy[left] += lazy[ti];
			lazy[right] += lazy[ti];
		}
		lazy[ti] = 0;
	}
	
	if(ts > ae or te < as)
		return 0;



	if(as >= ts and ae <= te)
		return tree[ti];

	return getsum(left, as, mid, ts, te) + getsum(right, mid+1, ae, ts, te);
}

int main()
{
	ios::sync_with_stdio(false);
	lli t, n, a, b, c, x, v;
	cin>>t;

	while(t--)
	{
		cin>>n>>c;
		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));

		while(c--)
		{
			cin>>x>>a>>b;
			if(x==0)
			{
				cin >> v;
				update(0, 0, n-1, --a, --b, v);
			}
			else{
				cout<<getsum(0, 0, n-1, --a, --b)<<"\n";
			}
		}
	}
}
