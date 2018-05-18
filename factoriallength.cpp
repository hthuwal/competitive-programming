/*use stirling's approximation*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define pi 4*atan(1)

int main()
{
	long long int t,n,x	;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==0||n==1)
			printf("1\n");
		else
		{
			x=floor((0.5*log10(2*pi*n))+n*(log10(n/exp(1))));
			x++;
			printf("%lld\n",x);
		}
	}
}	