/**
 * https://www.hackerrank.com/challenges/triple-sum
 */

#include<bits/stdc++.h>
#define lli long long int
#define vi vector<lli>
using namespace std;

void print(vi a)
{
	for(auto x: a)
		cout<<x<<" ";
	cout<<endl;
}
int main()
{
	lli a, b, c;
	scanf("%lld %lld %lld",&a,&b,&c);
	vi arra(a), arrb(b), arrc(c);
	for(int i=0;i<a;i++)
		scanf("%lld",&arra[i]); 
	for(int i=0;i<b;i++)
		scanf("%lld",&arrb[i]);
	for(int i=0;i<c;i++)
		scanf("%lld",&arrc[i]);

	set<lli> temp(arra.begin(), arra.end());
	arra = vi(temp.begin(), temp.end());
	temp = set<lli>(arrb.begin(), arrb.end());
	arrb = vi(temp.begin(), temp.end());
	temp = set<lli>(arrc.begin(), arrc.end());
	arrc = vi(temp.begin(), temp.end());

	// print(arra);
	// print(arrb);
	// print(arrc);

	// cout<<endl;
	lli ans = 0;
	for(int i=0;i<arrb.size();i++)
	{
		lli p = upper_bound(arra.begin(), arra.end(), arrb[i]) - arra.begin();
		lli q = upper_bound(arrc.begin(), arrc.end(), arrb[i]) - arrc.begin();
		ans += p*q;
		// cout<<p<<" "<<q<<" "<<ans<<endl;
	}
	cout<<ans;
}