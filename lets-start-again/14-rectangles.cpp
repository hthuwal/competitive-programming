/**
 * https://www.spoj.com/problems/AE00/
 *
 *  L x H <= N , L <= H
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	int n, ans=0;
	cin>>n;
	for(int i=1; i*i<=n;i++)
		ans += (n/i - i + 1);

	cout<<ans;
}