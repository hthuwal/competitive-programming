/**
 * https://www.hackerrank.com/challenges/pairs
 */
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
	int n, k;
	scanf("%d %d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	sort(a, a+n);

	lli ans = 0;
	for(int i=0;i<n;i++)
	{
		int target = a[i] + k;
		int lb = lower_bound(a+i+1, a+n, target) - (a+i+1);
		int ub = upper_bound(a+i+1, a+n, target) - (a+i+1);
		ans += ub - lb;
		// printf("%d %d %d %d %d\n", a[i], target, lb, ub, ans);
	}
	printf("%lld", ans);
}