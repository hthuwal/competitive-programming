// https://www.spoj.com/submit/GERGOVIA/

#include<iostream>

using namespace std;

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		long long int a[n];
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);

		long long int cost = 0;

		for(int i=n-1;i>0;i--)
		{
			cost += abs(a[i]);
			a[i-1] += a[i];
		}
		printf("%lld\n", cost);
	}
}