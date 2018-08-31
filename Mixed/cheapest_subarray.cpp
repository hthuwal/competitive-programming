#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,a[33333];
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);

		int ans = a[0]+a[1];
		for(int i=0;i<n-1;i++)
		{
			if(a[i]+a[i+1] < ans)
				ans = a[i]+a[i+1];
		}
		printf("%d\n", ans);
	}
}