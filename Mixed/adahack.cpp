#include <cstdio>
#define lli long long int
#define M 100000000003

lli exp(lli a, lli b)
{
	a = a%M;
	b = b%M;
	printf("%lld %lld\n",a,b);
	lli ans = 1;
	while( b > 0)
	{
		if(b%2==1)
			ans = (ans * a)%M;

		a = (a*a)%M;
		b = b/2;
		printf("%lld\n",a);
	}
	return ans;
}

lli multiplicative_inverse(lli a)
{
	return exp(a, M-2)%M;
}

int main()
{
	// lli x[6];
	// while(scanf("%lld",&x[0])!=EOF)
	// {
	// 	for(int i=1;i<6;i++)
	// 		scanf("%lld", &x[i]);
	// 	lli a = ((x[2]-x[1]+M)*multiplicative_inverse(x[1]-x[0]+M))%M;
	// 	lli b = (x[1]-a*x[0]+M)%M;
	// 	printf("%lld %lld %lld\n",a,b,(a*x[5]+b)%M );
	// }	
	printf("%lld",multiplicative_inverse(4));
}