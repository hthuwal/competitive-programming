#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int main()
{
	int n, r;
	ios::sync_with_stdio(false);
	cin>>n>>r;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int iolhs = -1;
	int ioll = -r;
	int iolal = -r;
	int ans = 0;
	// cout<<-1<<" "<<iolal<<" "<<ioll<<" "<<iolhs<<endl;
	for(int i=0;i<n;i++)
	{
		for
		if(a[i] == 1)
			ioll = i;

		if(i-iolhs == r || (i==n-1 && iolhs != i))
		{
			if(iolal == ioll)
			{
				ans = -1;
				break;
			}
			else
			{
				iolal = ioll;
				ans ++;
			}
		}
		
		if(i <= (iolal+r-1))
			iolhs = i;
		// cout<<i<<" "<<iolal<<" "<<ioll<<" "<<iolhs<<endl;
	}
	cout<<ans;

}