/*The number of divisors of a number, say 'n' can be computed using its prime factorisation.

If n = P1^b1 * P2^b2 * … Pk^bk, then the number of divisors of 'n' will be (b1+1)*(b2+1)*…(bk+1).

The exponent of a prime 'p' in the prime factorisation of n! is n/p + n/p^2 + …. until n/p^k equals zero for some 'k'.

This process is repeated for all primes less than 'n', the complexity of this solution is O(p*log(n)) where, 'p' is the number of primes <= n, and is roughly O(n), this approach is not fast enough.

Let's take a look at the expression for finding the exponent of a prime in n! :

n/p + n/p^2 + n/p^3 + …. n/p^k

What if ‘p’ is larger than sqrt (n) ? All terms other than the first one are going to become zero. Also, n/p itself cannot be larger than sqrt(n), so the exponents of all these primes are going to be in the range [1, sqrt(n) ). Also, all the primes having the same value for n/p are going to be consecutive.

If the number of primes whose exponent is 'i', ( 1 <= i <= sqrt(n) ) is ai, then we can simply multiply our result by (i + 1 ) ^ ai. How do we find ai ?

Let's first precompute an array cnt, where :

cnt [i] is the number of primes <= i, this can be done quickly using a sieve.

ai is the number of primes such that n/ai = i, therefore ai = cnt[ n/i ] - cnt[ n/(i+1) ].

Overall, the complexity of this solution will be O( sqrt (n) * log (n) ) per test case, which is fast enough to get accepted.*/
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define N 55555
#define ROOTN 240
#define lli long long int

int prime_arr[N]={0};
vector<int> prime;

/*fast sieve*/
void sieve()
{
    lli i,j,k;
    prime.push_back(2);

    for(i=3;i<=ROOTN;i+=2)
    {
        /* go to next*/
        while(prime_arr[i]==1)
            i+=2;

        j = i*(i-2);
        k = i<<1;

        for(lli l = j+k;l<=N;l+=k)
            prime_arr[l]=1;
    }

    for(i=3;i<=N;i+=2)
    {
        if(prime_arr[i]==0)
        {
            prime.push_back(i);
        }
    }
}


lli number_of_divisors_slow(lli n, lli m)
{
    lli ans = 1;
    for(int i=0;n/prime[i]>0;i++)
    {
        lli p = prime[i];
        lli power_of_p_in_nfact = 0;

        while(n/p > 0)
        {
            power_of_p_in_nfact += (n/p);
            p=p*prime[i];
        }

        ans = (ans * (power_of_p_in_nfact + 1));
        if(ans>=m)
            ans = ans%m;
    }
    return ans;
}

lli number_of_divisors_fast(lli n, lli m)
{
    int i;
    for(i=0;i< len && prime[i]*prime[i] <= n; i++)
    {
        lli p = prime[i];
        lli power_of_p_in_nfact = 0;
    
        while(n/p > 0)
        {
            power_of_p_in_nfact += (n/p);
            p = p*prime[i];
        }
        ans = ans * (power_of_p_in_nfact + 1);
        if(ans>=m)
            ans = ans%m;
    }

    lli index = i; //prime[i]*prime[i] just gt or eq to n
                   //from this onwards no prime can divide perfectly

    lli j = n/prime[i];

    for(;j>=1 && i<len; j--)
    {
        lli check = n/j;
        lli low = i;
        lli high = ((n/2 + 1) >= len) ? len - 1 : n/2 + 1;
        
        while(low<high)
        {
            lli mid = (high+low>>1);
            if(prime[mid]<=check){
                low = mid + 1;
            } else{
                high = mid;
            }
        }
        lli count = low - index;
        index = low;
        ans = ((ans % m) * ((power(j+1 , count , m)) % m)) % m;
        
    }
}
int main()
{
    sieve();
    printf("%lld",number_of_divisors_slow(4567,1000000007));
}