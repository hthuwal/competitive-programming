#include <cstdio>
#include <cstdlib>
using namespace std;
#define ll long long

ll modulo(ll base,ll exp,ll mod)
{
	
	ll x = 1;
	ll y = base;
	while(exp>0)
	{
		if(exp%2==1)
			x=(x*y)%mod;
		y=(y*y)%mod;
		exp = exp/2;
	}
	return x%mod;
}
bool fermat(ll p,ll iter)
{
	if(p==1)
		return false;
	for(int i=0;i<iter;i++)
	{
		ll a = rand() % (p-1)+1;
		if(modulo(a,p-1,p)!=1)
		{
			return false;
		}
	}
	return true;

}
int main()
{
	freopen("in.txt","r",stdin);
	ll t,n;
	for(scanf("%lld",&t);t--;)
	{
		scanf("%lld",&n);
		if(fermat(n,20))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

