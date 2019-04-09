/**
 * SPOJ: https://www.spoj.com/problems/TDKPRIME/
 */
#include<stdio.h>

#define N 5000001
#define lli long long int
#define MAX 87000008

int primes[N];
bool sieve[MAX] = {0};

void preprocess()
{
	int k = 0;
	primes[k++] = 2;
	for(lli i=3;i<MAX;i+=2)
	{
		// If sievie[i] is false, then it is a prime
		if(sieve[i] == false)
		{
			primes[k++] = i;

			/**
			 * Update all multiples of i greater than or
			 * equal to the square of it 
			 * numbers which are multiple of i and are 
			 * less than i^2 are already been marked. 
			 */
			for(lli j=i*i; j<MAX; j+=i)
				sieve[j] = true;
		}
		if(k == N-1)
			break;
	}
}

int main()
{
	preprocess();
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n", primes[--n]);
	}
}