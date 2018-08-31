#include <cstdio>
#define lli long long int
int main()
{
	int n;
	int a[300004];
	scanf("%d",&n);
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		/* code */
	}
	int max_of_sec = -1,m,x;
	scanf("%d",&m);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&x);
		if(x>max_of_sec)
			max_of_sec = x;
	}

	lli ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < max_of_sec + 1)
			ans += (max_of_sec + 1 - a[i]);
	}
	printf("%lld", ans);
}