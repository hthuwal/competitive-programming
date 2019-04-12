/**
 * https://codeforces.com/problemset/problem/1119/A
 */
#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	int n;
	cin>>n;

	int c[n];
	map<int, int> minloc;
	map<int, int> maxloc;

	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		if(minloc.find(c[i]) == minloc.end())
			minloc[c[i]] = i;

		maxloc[c[i]] = i;
	}

	int ans = 0;
	for(int i=0;i<n;i++)
	{
		int color = c[i];
		if(maxloc[color] != n-1 and n-1-i > ans)
			ans = n-1-i;

		if(minloc[color] != 0 and i > ans)
			ans = i;
	}
	cout<<ans;
}