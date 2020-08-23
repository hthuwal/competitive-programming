#include<bits/stdc++.h>

using namespace std;

int cost(int a[], int n, int x)
{
	int cost = 0;
	for(int i=0;i<n;i++)
	{
		int me = i+1;
		int temp = abs(x-me);
		temp += me - 1;
		temp += x - 1;
		cost += 2*temp*a[i];
	}
	return cost;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	int ans = INT_MAX;
	for(int x=1;x<=n;x++)
	{
		int temp = cost(a, n, x);
		if(temp < ans)
			ans = temp;
	}
	cout<<ans<<endl;
}