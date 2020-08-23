#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

#define N 100000009
#define ROOTN 10000
#define lli long long int

int prime_arr[N]={0};
vector<int> prime;

inline void fastscan(lli &x)
{  
    register char c=0;
    while (c<33) c=getchar_unlocked();
    x=0;
    while (c>33)
    {
        x=x*10+c-'0';
        c=getchar_unlocked();
    }
}

void sieve(){
    lli i,j,k;
    prime.push_back(2);
    for(i=3;i<=ROOTN;i+=2)
    {
        /* go to next prime*/
        while( prime_arr[i]==1)
            i+=2;
            
        j = i*(i-2);
        k = i << 1;
        
        /* for(l=j;l<=N;l+=k)*/
        /* start form j and incrementing by k i.e 2*the prime number*/
        while((j = k + j) <= N)
            prime_arr[j]=1;
    }
    for(i=3;i<=N;i+=2)
    {
        if(prime_arr[i]==0){
            prime.push_back(i);
        }
    }
}
lli power(lli a,lli b, lli c)
{
    lli ans = 1;
    while(b>0)
    {
        if(b&1)
            ans = (ans * a) % c;
        a = (a*a)%c;
        b = b>>1;
    }
    return ans % c;
}
lli number_of_divisors(lli n, lli m)
{
    lli len = prime.size();
    lli ans = 1;
    /* Calculating Powers of all primes gives tle*/


    /* Calculate only upto square root of n */
    int i;
    for(i=0;i<len && prime[i]*prime[i] <=n ;i++)
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
        lli high =  ((n/2 + 1) >= len) ? len - 1 : n/2 + 1;
        
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


    ans = ans-1;
    if(ans<0)
        ans += m;
    return ans;
}
int main(){
    sieve();
    lli n,t,m;
    for(scanf("%lld",&t);t--;)
    {
        fastscan(n);
        fastscan(m);
        printf("%lld\n",number_of_divisors(n,m));
    }
}
