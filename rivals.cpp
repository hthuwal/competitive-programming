#include <cstdio>
#define lli long long int
#define M 1000000007
lli fact[2222222];

/**precompute factorials**/
void precompute_fact()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<2222222;i++)
    {
        fact[i]=(i*fact[i-1])%M;
    }
}

/** To compute x^y modulo m**/
lli modulo_power(lli x, lli y)
{
    x = x % M;
    lli ans = 1;

    while(y>0)
    {
        if(y%2==1)
        {
            ans = (ans * x);
            if(ans>M)
                ans = ans%M;
        }
        y = y/2;
        x = (x * x) % M;
    }
    return ans;
}

/* If we know m is prime, then we can also use Fermats’s little theorem to find the inverse.

a^(m-1) ≡ 1 (mod m)  
If we multiply both sides with a-1, we get

 a^(-1) ≡ a^(m-2) (mod m)*/
lli modulo_inverse(lli x)
{
    return modulo_power(x, M-2);
}

/*to compute x+yCy*/
lli modulo_nCr(lli x, lli y)
{
    lli hc = modulo_inverse((fact[x-y] * fact[y])%M); 
    return (fact[x] * hc) % M;
}


/*
number of ways of reaching (x,y) form (0,0)
using steps one unit right or one unit up
we hhave to move right x times and up y times

therefore the problem reduces to 
number of ways of rearranging x R's and y U's 
which is

(x+y)! / x! y! or (x+y)Cx
*/
lli num_of_ways(lli x, lli y)
{
    return modulo_nCr(x+y,(x>y?x:y));
}

inline void fastscan(int &x)
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

int main()
{
    int t,x,y;
    precompute_fact();
    for(scanf("%d",&t);t--;)
    {
        fastscan(x);
        fastscan(y);
        printf("%lld\n",num_of_ways(x,y));
    }
}