/**
 * https://www.spoj.com/problems/FACT0/
 */

#include<bits/stdc++.h>
#define lli long long int
using namespace std;


void print_factorization(lli n)
{
	lli sqrtn = sqrt(n);
	
	lli count = 0;
	while(n % 2 == 0)
	{
		count ++;
		n /= 2;
	}
	if(count != 0)
		cout<<2<<"^"<<count<<" ";

	for(lli i=3; i<=sqrtn and n>=1; i+=2)
	{
		count = 0;
		while(n % i == 0)
		{
			count ++;
			n /= i;
		}
		if(count != 0)
			cout<<i<<"^"<<count<<" ";
	}

	if(n!=1)
		cout<<n<<"^1";
	
	cout<<"\n";
}

int main()
{
	cin.sync_with_stdio(false);
	lli n;
	cin >> n;
	while(n!=0)
	{
		print_factorization(n);
		cin >> n;
	}
}