/**
 * Microsoft: https://practice.geeksforgeeks.org/problems/stickler-theif/0
 */

#include<bits/stdc++.h>
using namespace std;
int a[1001];
int ans(int n)
{
    int dp[n];
    dp[0]=a[0];
    dp[1]=max(a[0], a[1]);
    for(int i=2;i<n;i++)
        dp[i] = max(dp[i-2] + a[i], dp[i-1]);
    return *max_element(dp, dp+n);
}
int main()
 {
	int t, n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<ans(n)<<"\n";
	}
	return 0;
}