/*
we need to find all possible values of x and n 
that satisfy the next equation
n >= 2, x>=1
N! = x + (x+1) + (x+2) .... (x+n-1) ---- A 
N! = nx + n*(n-1)/2
2*N! = n*(2*x+n-1)
2*N! = p * q   ---- B

therefore number of posible values of x and n in A
is equal to the number of possible values of p and q in B
where p<q

also if n is even => p is even and q is odd
        n is odd => p is odd and q is even

therefore are answer is number of odd divisors of 2*N!
i.e odd divsiors of N! 
excluding 1 because p =1 => n =1 and n must be greater than 2
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define lli long long int
#define N 100000009
#define gc getchar_unlocked
int prime_arr[N]={0};
vector<lli> prime;

void sieve () {
	long long i , j , i2 ;
	for( i = 3 ; i <= 9999 ; i += 2 ) { //9999 is sqrt(MAX)
		while( prime_arr[i] == 1 )
			i += 2;
		j = i*(i-2);
		i2 = i << 1 ;
		while( ( j = i2 + j ) <= N )
			prime_arr[j] = 1;
	}
	
	for( i = 3 ; i <= N ; i += 2 ){
		if( prime_arr[i] ==0){
			prime.push_back(i) ;
		}
		//cout << len <<"\n";			//5761454
	}
	// printf("%ld\n",prime.size());
}

inline void fastscan(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
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
int main()
{
    sieve();
    // printf("%ld\n", prime.size());
    // freopen("in.txt","r",stdin);
    int t,n,m;
    int len = prime.size();
    fastscan(t);
    for(;t--;)
    {
        fastscan(n);fastscan(m);
        lli ans = 1;
        /* Calculating Powers of all primes gives tle*/


        /* Calculate only upto square root of n */
        int i;
        for(i=0;i<len && prime[i]*prime[i] <=n ;i++)
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
        printf("%lld\n",ans);
    }

    
}