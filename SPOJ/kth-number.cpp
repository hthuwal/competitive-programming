/**
 * https://www.spoj.com/submit/MKTHNUM/
 *
 * O(n*m) TLE
 */

#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int partition(vector<int> &a, int l, int r)
{
	if(l!=r)
	{
		int pivot = rand() % (r-l+1) + l;
		swap(a[l], a[pivot]);
	}	

	int x = a[l];
	int i = l;

	for(int j=i+1;j<=r;j++)
		if(a[j]<x)
			swap(a[++i], a[j]);
	swap(a[l], a[i]);
	return i;
}

int kth_highest(vector<int> &a, int l, int r, int k)
{
	int p = partition(a, l, r);
	if(p == k)
		return a[p];
	else if(p < k)
		return kth_highest(a, p+1, r, k);
	else
		return kth_highest(a, l, p-1, k);
}

int main()
{
	int n, m, l, r, k;
	scanf("%d %d",&n,&m);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&l, &r, &k);
		--l; --r; --k;
		vector<int> temp(a+l, a+r+1);
		printf("%d\n", kth_highest(temp, 0, r-l, k));
	}
}