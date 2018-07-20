#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

void solve(vi &a, vi &c)
{
	vi b;
	for(int i=0;i<c.size();i++)
	{
		for(int j=0;j<a.size();j++)
		{
			if(c[i]-a[j] >=0 && c[i]-a[j] <= 100)
				b.push_back(c[i]-a[j]);
		}
	}
	vi hash(101,0);
	for(int i=0;i<c.size();i++)
		hash[c[i]] = 1;

	for(int i=0; i<a.size();i++)
	{
		for(int j=0; j<b.size(); j++)
		{
			if(a[i]+b[j] > 100 || hash[a[i]+b[j]] == 0)
				b[j] = -1;
		}
	}

	set<int> hc(b.begin(), b.end());
	b = vi(hc.begin(), hc.end());

	sort(b.begin(), b.end());
	for(int i=0;i<b.size();i++)
	{
		if(b[i]!=-1)
			printf("%d ", b[i]);
	}
}
int main()
{
	int n,m,x;
	vi a,c;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		a.push_back(x);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		c.push_back(x);
	}
	solve(a,c);
}