#include <bits/stdc++.h>
#define lli long
#define N 33554432

int lazy[N]={0};
lli tree[N]={0};

lli max(lli a, lli b)
{
	return a>b?a:b;
}


void update(int ti, int ss, int se, int ul, int ue, int value)
{
	int left = 2*ti + 1;
	int right = 2*ti + 2;

	if (lazy[ti] != 0)
	{
		tree[ti] += lazy[ti];
		if(ss != se)
		{
			lazy[left] += lazy[ti];
			lazy[right] += lazy[ti];
		}
		lazy[ti] = 0;
	}

	if(ss > se || ss > ue || se < ul)
		return ;

	if(ul <= ss && ue >= se)
	{
		tree[ti] += value;

		if(ss != se)
		{
			lazy[left] += value;
			lazy[right] += value;
		}
		return;
	}

	int mid = (ss + se)/2;
	update(left, ss, mid, ul, ue, value);
	update(right, mid+1, se, ul, ue, value);
	tree[ti] = max(tree[left], tree[right]);
}

int main()
{
	int n,m,l,h,v;
	scanf("%d %d",&n,&m);

	for(int i=0; i<m;i++)
	{
		scanf("%d %d %d",&l,&h,&v);
		update(0, 0, n-1, l-1, h-1, v);
	}
	printf("%lld\n",tree[0]);
}