#include<stdio.h>
#define x 10000007
long long int a[x]={0};
long long int harish(long long int k)
{
	if(k<12)
		return k;
	else if(k<x)
	{
		if(a[k]==0)
		{
			a[k]= harish(k/2)+harish(k/3)+harish(k/4);
			return a[k];
		}
		else
			return a[k];
	}
	else
		return harish(k/2)+harish(k/3)+harish(k/4);
}
int main()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",harish(n));
	}
	return 0;
}

