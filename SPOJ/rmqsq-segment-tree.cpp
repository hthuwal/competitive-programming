/**
 * https://www.spoj.com/problems/RMQSQ/
 * Online Query Evaluation
 */

#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
#define N 100005
using namespace std;

int a[N];
int tree[3*N];


void create(int ti, int si, int ei)
{
	if(si == ei)
		tree[ti] = a[si];
	else if(si<ei)
	{
		int mid = si+((ei - si)>>1);
		int left = 2*ti+1;
		int right = 2*ti+2;
		create(left, si, mid);
		create(right, mid+1, ei);
		tree[ti] = min(tree[left], tree[right]);
	}
}

int get(int ti, int si, int ei, int qs, int qe)
{
	if(qs <= si && qe >= ei)
		return tree[ti];

	if(qs > ei or qe < si)
		return INT_MAX;

	int mid = si+((ei - si)>>1);
	int left = 2*ti+1;
	int right = 2*ti+2;
	return min(get(left, si, mid, qs, qe), get(right, mid+1, ei, qs, qe));
}

int main()
{
	ios::sync_with_stdio(false);
	int n,q,l,r;
	cin>>n;
	
	// Take Input
	f(i,n) cin>>a[i];
	create(0, 0, n-1);

	cin>>q;
	f(i, q)
	{
		cin>>l>>r;
		cout<<get(0, 0, n-1,l, r)<<endl;
	}
}