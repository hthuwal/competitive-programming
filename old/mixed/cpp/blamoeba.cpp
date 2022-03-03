/*
    Amoeba's left After 
    day 1 : x*m-y
    day 2: x*m^2 - ym -y
    

    day n: x*m^n - y*m^(n-1) - y*m^(n-2)..... - y
    after day n no amoeba should be left
    day n = 0
    solve for x
    x = y ((m^n - 1)/ (m^n)*(m-1))
    x should be integer therefore y = m^n
*/
#include <cstdio>
#define lli long long int
#define M 1000000007

lli exp(lli a, lli b)
{
    a = a % M;
    lli ans = 1;

    while(b>0)
    {
        // if power is odd
        if(b&1)
            ans = ((ans % M)*(a % M)) % M;
        
        // now power must be even
        b = b >> 1;
        a = (a*a) % M;
    }

    return ans % M;
}


int main()
{
    lli t,m,n;
    freopen("in.txt","r",stdin);
    for(scanf("%lld",&t);t--;)
    {
        scanf("%lld %lld",&m,&n);
        lli dr = (m-1);
        lli y = exp(m,n);
        lli inv_of_dr = exp(dr,M-2);
        lli nr = (y - 1 + M )%M;
        lli x = (nr * inv_of_dr)%M;
        printf("%lld %lld\n",x,y);
    }
}