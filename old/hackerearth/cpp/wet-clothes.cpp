/**
 * https://www.hackerearth.com/challenges/competitive/march-circuits-19/algorithm/wet-clothes-625348cf/
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, g;
	cin.sync_with_stdio(false);
	cin>>n>>m>>g;
	int t[n];
	int a[m];
	
	for(int i=0;i<n;i++)
		cin>>t[i];

	for(int i=0;i<m;i++)
		cin>>a[i];

	for(int i=0;i<n-1;i++)
		t[i] = t[i+1] - t[i];

	sort(t, t+n-1);
	
	int i=n-2;
	while(g>0 and i>=0)
	{
		for(int j=0;j<m;j++)
		{
			if(a[j] != -1 and a[j]<=t[i])
				a[j] = -1;
		}
		g--; i--;
	}
	int ans = 0;
	for(int i=0;i<m;i++)
		if(a[i] == -1)
			ans ++;
	cout<<ans;
}