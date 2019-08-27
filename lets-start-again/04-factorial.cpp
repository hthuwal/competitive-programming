// https://www.spoj.com/status/FCTRL,hthuwal/

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define lli long long int

/**
 * Return the power of x in n!
 */
lli powersofx(lli n, lli x)
{
	lli p = x;
	lli co2 = 0;

	while(n >= p)
	{
		co2 += n / p;
		p = p * x;
	}
	return co2;
}

int main()
{
	lli t, n;
	cin.sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<powersofx(n, 5)<<"\n";
	}
}