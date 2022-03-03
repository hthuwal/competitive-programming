#include <iostream>
#include <cstdio>
#define MOD 100000007
using namespace std;
int a[1100000];
long long int pow(long long base, long long power)
{
	if(power==0)
		return 1;
	else if(power==1)
		return base;
	else
	{
		long long half = pow(base,power/2);
		if(power%2==0)
			return ((half%MOD)*(half%MOD))%MOD;
		else
			return ((((half%MOD)*(half%MOD))%MOD)*(base%MOD))%MOD;
	}
}

/**
 * If we know m is prime, then we can also use Fermats’s little theorem to find the inverse.
				am-1 ≡ 1 (mod m)  
	If we multiply both sides with a-1, we get
				a-1 ≡ a^(m-2) (mod m)
	
	a^(m-2) is the multiplicative inverse of
*/

long long int findMMI_fermat(long long int n)
{
	return pow(n,MOD-2);
}

/* 
   So, if we are performing modulo arithmetic in our program and we need the result of
    the operation x / y, we should NOT perform
   z=(x/y)%M;
   instead we should perform
   y2=findMMI(y,M);
   z=(x*y2)%M;
 */


long long int C(long long int n,long long int r)
{
	long long int nr=1;
	long long int dr=1;	
	for(int i=0;i<r;i++)
	{
		nr= ((nr%MOD)*(n-i)%MOD)%MOD;
		dr = ((dr%MOD)*(i+1)%MOD)%MOD;
	}
	//ncr = (nr/dr)%MOD
	//x = MMI(dr);
	//ncr = (nr*x)%M
	long long int ncr;
	long long int mmi = findMMI_fermat(dr);
	ncr = ((nr%MOD)*(mmi%MOD))%MOD;
	return ncr;
}

long long int hc(long long int n)
{
	a[0]=1;
	a[1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=0;
		if(i%2==0)
		{
			for(int j=0;j<=(i-2);j+=2)
			{
				a[i]+=(C(i-j,2)%MOD);
			}
			for(int j=2;j<=i;j+=2)
			{
				a[i]+=((C(i,j)%MOD)*(a[i-j])%MOD)%MOD;
			}
		}
		else
		{
			for(int j=0;j<=(i-2-1);j+=2)
			{
				a[i]+=(C(i-j,2)%MOD);
			}
			for(int j=3;j<=i;j+=2)
			{
				a[i]+=((C(i,j)%MOD)*(a[i-j])%MOD)%MOD;
			}
		}
	}
	return a[n];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long long int t,n;
	// /cout<<(C(10,3));
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<hc(n)<<"\n";
	}
}