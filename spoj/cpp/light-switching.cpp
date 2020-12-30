/**
 * https://www.spoj.com/problems/LITE/
 *
 * Segment Tree with Lazy Propogation
 */
#include<bits/stdc++.h>
using namespace std;
#define N 100005

int tree[3*N];
bool lazy[3*N];

void update(int ti, int as, int ae, int rs, int re)
{
	int left = 2*ti+1;
	int right = 2*ti+2;
	int mid = as + ((ae-as)>>1);

	if(lazy[ti])
	{
		tree[ti] = (ae-as+1)-tree[ti];
		if(ae!=as)
		{
			lazy[left] = (!lazy[left]);
			lazy[right] = (!lazy[right]);
		}
		lazy[ti] = false;
	}

	if(as > re || ae < rs)
		return;

	if(as >= rs and ae <= re)
	{
		tree[ti] = (ae-as+1)-tree[ti];
		if(ae!=as)
		{
			lazy[left] = !lazy[left];
			lazy[right] = !lazy[right];
		}
	}
	else
	{
		update(left, as, mid, rs, re);
		update(right, mid+1, ae, rs, re);
		tree[ti] = tree[left] + tree[right];
	}
}

int get(int ti, int as, int ae, int rs, int re)
{
	int left = 2*ti+1;
	int right = 2*ti+2;
	int mid = as + ((ae-as)>>1);

	if(lazy[ti])
	{
		tree[ti] = (ae-as+1)-tree[ti];
		if(ae!=as)
		{
			lazy[left] = !lazy[left];
			lazy[right] = !lazy[right];
		}
		lazy[ti] = 0;
	}

	if(as > re || ae < rs)
		return 0;

	if(as >= rs and ae <= re)
		return tree[ti];
	else
	{
		return get(left, as, mid, rs, re) + get(right, mid+1, ae, rs, re);
	}
}

int main()
{
	// ios::sync_with_stdio(false);
	int n, m,x,a,b;
	// cin>>n>>m;
	scanf("%d %d",&n,&m);

	memset(tree, 0, sizeof(tree));
	memset(lazy, false, sizeof(lazy));

	for(int i=0;i<m;i++)
	{
		// cin>>x>>a>>b;
		scanf("%d %d %d",&x,&a,&b);
		if(x==0)
			update(0, 0, n-1, --a, --b);
		else
			// cout<<get(0, 0, n-1, --a, --b)<<"\n";
			printf("%d\n",get(0, 0, n-1, --a, --b));
	}

}