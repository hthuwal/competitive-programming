#include <bits/stdc++.h>
using namespace std;

#define N 111111
#define tN 666666

int a[N];
int atree[tN];
int xtree[tN];
int otree[tN];

void create(int ti, int l, int h)
{
	if (l>h)
		return;

	if(l==h)
	{
		atree[ti] = xtree[ti] = otree[ti] = a[l];
		return;
	}

	int mid = (l+h)>>1;

	create(2*ti, l, mid);
	create(2*ti + 1, mid + 1, h);

	atree[ti] = atree[2*ti] & atree[2*ti + 1];
	xtree[ti] = xtree[2*ti] ^ xtree[2*ti + 1];
	otree[ti] = otree[2*ti] | otree[2*ti + 1];
}

void update(int ti, int l, int h, int i, int x)
{
	if(i < l || i > h)
		return;

	if(l==h && l==i)
	{
		atree[i] = xtree[i] = otree[i] = x;
		return;
	}
	else if (l==h)
		return;

	int mid = (l+h)>>1;

	update(2*ti, l, mid, i, x);
	update(2*ti + 1, mid + 1, h, i, x);

	atree[ti] = atree[2*ti] & atree[2*ti + 1];
	xtree[ti] = xtree[2*ti] ^ xtree[2*ti + 1];
	otree[ti] = otree[2*ti] | otree[2*ti + 1];

}

int get_or(int ti, int l, int h, int i, int j)
{
	if(h < i || j < l)
		return 0;
	if(h >= j && i >= l)
		return otree[ti];

	int mid = (l+h)>>1;
	int left = get_or(2*ti, l, mid, i, j);
	int right = get_or(2*ti+1, mid+1, h, i, j);

	return left | right;
}

int get_xor(int ti, int l, int h, int i, int j)
{
	if(h < i || j < l)
		return 0;
	if(h >= j && i >= l)
		return xtree[ti];

	int mid = (l+h)>>1;
	int left = get_xor(2*ti, l, mid, i, j);
	int right = get_xor(2*ti+1, mid+1, h, i, j);

	return left ^ right;
}

int get_and(int ti, int l, int h, int i, int j)
{
	if(h < i || j < l)
		return INT_MAX;
	if(h >= j && i >= l)
		return atree[ti];

	int mid = (l+h)>>1;
	int left = get_and(2*ti, l, mid, i, j);
	int right = get_and(2*ti+1, mid+1, h, i, j);

	return left & right;
}

int main()
{
	int n, q, type, i, j, x;
	string op;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	create(1, 0, n-1);
	// for(int i=0;i<8;i++)
	// 	cout<<otree[i]<<" ";
	for(int k=0;k<q;k++)
	{
		cin>>type;
		if(type == 1)
		{
			cin>>x>>i;
			update(1, 0, n-1, i, x);
		}
		else{
			cin>>op>>i>>j;
			if(op=="OR")
				cout<<get_or(1, 0, n-1, --i, --j);
			else if(op=="AND")
				cout<<get_and(1, 0, n-1, --i, --j);
			else if(op=="XOR")
				cout<<get_xor(1, 0, n-1, --i, --j);
		}
	}
}