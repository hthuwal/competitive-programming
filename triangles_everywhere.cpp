#include <cstdio>
#define M 1000000007
#define lli long long int

lli expm(lli a, lli b)
{
	a = a%M;
	lli ans = 1;
	while(b!=0)
	{
		if(b&1)
			ans = (ans*a)%M;

		a = (a*a)%M;
		b = b>>1;
	}
	return ans;
}


int main()
{
	lli q,n;
	for(scanf("%lld",&q);q--;)
	{
		scanf("%lld",&n);
		printf("%lld\n", (((expm(3,n)-1)*2)%M+1)%M);
	}
}