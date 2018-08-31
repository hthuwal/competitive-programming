#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

#define N 55555
#define ROOTN 240
#define lli long long int

int prime_arr[N]={0};
vector<int> prime;

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

void sieve(){
    lli i,j,k;
    prime.push_back(2);
    for(i=3;i<=ROOTN;i+=2)
    {
        /* go to next non prime*/
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

lli number_of_divisors(lli n, lli m)
{
    lli ans = 1;
    for(int i=0;n/prime[i]>0;i++)
    {
        lli p = prime[i];
        int power_of_p_in_nfact = 0;

        while(n/p > 0)
        {
            power_of_p_in_nfact += (n/p);
            p = p*prime[i];
        }

        ans = ans * (power_of_p_in_nfact + 1);
        if(ans>=m)
            ans = ans%m;
    }
    return ans;
}
int main(){
    sieve();
    int n,t;
    for(scanf("%d",&t);t--;)
    {
        fastscan(n);
        printf("%lld\n",number_of_divisors(n,1000000007));
    }
}
