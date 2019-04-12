/**
 * https://codeforces.com/problemset/problem/1119/B
 */

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> a, int h)
{
	sort(begin(a), end(a));
	for(int i=a.size()-1;i>=0;i-=2)
	{
		if(h>=a[i])
			h -= a[i];
		else
			return false;
	}
	return true;
}

int main()
{
	int n, h;
	cin.sync_with_stdio(false);
	cin>>n>>h;
	vector<int> a(n, 0);
	for(int i=0;i<n;i++)
		cin>>a[i];

	for(int i=n-1;i>=0;i--)
	{
		if(isPossible(vector<int>(begin(a), begin(a)+i+1), h))
		{
			cout<<i+1;
			return 0;
		}
	}
	cout<<0;
}