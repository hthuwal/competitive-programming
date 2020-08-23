#include <cstdio>
#include <cstdlib>
#define toi long long int

/*evaluate (a^b)mod n*/
/*Culprit!! stops overflow only if a*a doesnt exceed long long int*//
toi exp(toi a,toi b,toi mod)
{
    toi ans = 1;
    a = a % mod;
    while(b>0)
    {
        if(b&1)
            ans = (ans * a) % mod;
        b=b>>1;//b/2
        a=(a*a) % mod;
    }    
    return ans;
}
/* Fermat's Little Theorem For prime p and a coprime to p. a^(p-1) % p = 1 
   Fails for Carmichael number as as they are odd composite numbers who satisfy this property e.g
*/
bool isPrimeUsingFermat(toi p,toi iter)
{
    if(p==1)
        return false;
    for(toi i=0;i<iter;i++)
    {
        toi a = rand()%(p-1)+1; // ensuring a and p are coprime
        if(exp(a,p-1,p)!=1)
            return false;
    }
    return true;
}
int main()
{
    int i,x;
    freopen("in.txt","r",stdin);
    for(scanf("%d",&i);i--;)
    {
        scanf("%d",&x);
        if(isPrimeUsingFermat(x,5000))
            printf("Yes\n");
        else
            printf("No\n");
    }
}