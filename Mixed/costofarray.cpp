#include <cstdio>
#include <algorithm>
#define lli long long int
typedef struct two{
	lli v;
	lli i;
}two;

using namespace std;

two a[27000];
two c[27000];
two b[27000];
lli cost [600][600];
int comp(two s, two t)
{
	return s.v > t.v;
}	

int main()
{
	lli n,m;
	scanf("%lld",&n);
	for(lli i=0;i<n;i++)
	{
		scanf("%lld",&a[i].v);
		a[i].i = i;
		c[i].v=a[i].v;
		c[i].i=a[i].i;
	}
	for(lli i=0;i<n;i++)
	{
		scanf("%lld",&b[i].v);
		b[i].i = i;
	}
	scanf("%lld",&m);
	for(lli i=0;i<m;i++)
		for(lli j=0;j<m;j++)
			scanf("%lld",&cost[i][j]);

	sort(a,a+n,comp);
	sort(b,b+n,comp);

	lli ans = 0;
	for(lli i=0;i<n;i++)
	{
		printf("%lld %lld\n",a[i].i, b[i].i);
		ans += (a[i].v * b[i].v);
		ans -= cost[a[i].v][c[b[i].i].v];
		c[a[i].i].v = c[b[i].i].v;
		c[b[i].i].v = a[i].v;
	}
	printf("%lld\n",ans);
}