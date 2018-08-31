/*
Truncky Number
    6
    56
    556
    5556

kth Truncky NUmber: (5/9) (10^n - 10) + 6

Sum of n Truncky Numbers
    6 + 56 + 556 + ...
    Summation (5/9) (10^n - 10) + 6
    
    = (5/81) (10^(n+1) - 90n -10) + 6k
*/
#include <cstdio>
#define lli long long int
#define M 1000000007 

lli exp(lli a, lli b)
{
    a=a % M;
    lli ans = 1;
    while(b>0)
    {
        // if power is odd
        if (b & 1)
            ans= ((ans % M)*(a % M)) % M;
        
        // now power must be even
        b = b >> 1; // b=b/2
        a = (a*a) % M;
    }
    return ans % M;
}

lli trucnky_sum(lli n)
{
    lli s = (( exp(10, n+1) - (90 * n)%M) % M + M)%M;
    s = ((s-10)%M+M)%M;
    s = (((s*5)%M)*((123456791)%M))%M;
    s = (s + (6*n)%M)%M;
    return (s+M)%M;
}
int main()
{
    freopen("in.txt","r",stdin);
    lli t,n;
    for(scanf("%lld",&t);t--;)
    {
        scanf("%lld",&n);
        printf("%lld\n",trucnky_sum(n));
    }
}