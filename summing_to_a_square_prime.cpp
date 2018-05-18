#include <cstdio>
#include <cstdlib>
#include <cstring>

#define lli int
lli hc[512];
int k = 0;

/* find a^n mod p*/
lli power_modulo(lli a, lli n, lli p)
{
    lli res = 1;
    a = a % p;
    while(n>0)
    {
        if( n & 1)
            res = (res*a)%p;
        a = (a*a)%p;
        n =  n>>1;
    }
    return res;
}

/*
Fermat's Little Theorem:
If n is a prime number, then for every a, 1 <= a < n,

an-1 ≡ 1 (mod n)
 OR 
an-1 % n = 1 
*/
bool isPrime(int p, int k)
{
    if(p==1)
        return false;
    for(int i=0;i<k;i++)
    {
        lli a = rand() % (p-1)+1;
        if(power_modulo(a,p-1,p)!=1)
        {
            return false;
        }
    }
    return true;
}

/*
2 = 1 + 1
and using
Fermat's theorem on sums of two squares states that an odd prime p is expressible as

 p=x^{2}+y^{2}

with x and y integers, if and only if

p mod 4 = 1
8209 is 510th such number
*/
void prime_sum_of_two_squares()
{
    for(int i = 5;k<510;i+=4)
    {
        if(isPrime(i,20))
        {
            hc[k++]=i;
        }

    }
}

int dp[9000][5];
void solve()
{
    for(int i=0;i<5;i++)
        dp[0][i]=1;
    for(int i=1;i<9000;i++)
    {
        for(int j=1;j<5;j++)
        {
            int p = j;
            if(i<j)
                p=i;

            for(int k=p;k>=1;k--)
            {
                dp[i][j]+=dp[i-k][k];
            }
        }
    }
}
int main()
{
    hc[k++]=2;
    prime_sum_of_two_squares();
    memset(dp,0,sizeof(dp));
    solve();
    int t,n,k;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d %d",&n,&k);
        printf("%d\n", dp[hc[n-1]][k]);
    }
}