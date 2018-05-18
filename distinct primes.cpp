#include <cstdio>
#define N 2700
int sieve[N];
int hash[N];
int primes[1500],prime;
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    /*preprocessing*/
    for(int i=0;i<N;i++)
    {
        sieve[i]=i;hash[i]=0;
    }
    for(int i=2;i<N;i++)
    {
        if(hash[i]==0)
        {
            for(int j=2*i;j<N;j+=i)
            {
                hash[j]++;
            }
        }
    }
    prime=0;
    for(int i=30;i<N;i++)
    {
        if(hash[i]>=3)
            primes[prime++]=i;
    }
    int t,n;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        printf("%d\n",primes[n-1]);
    }
    
}