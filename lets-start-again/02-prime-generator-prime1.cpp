// https://www.spoj.com/problems/PRIME1/

#include<bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define lli long long int

vi primes;

void sieve()
{
	vi temp(35000, 0);
	temp[2] = 0;
	temp[3] = 0;
	primes.push_back(2);

	for(int i=3; i*i<temp.size(); i+=2)
	{
		if(temp[i] != 1)
		{
			for(int j=2*i; j<temp.size(); j+=i)
			{
				temp[j] = 1;
			}
		}
	}
	for(int i=3;i<temp.size();i+=2)
	{
		if(temp[i] == 0)
			primes.push_back(i);
	}
}

bool isprime(lli x)
{
	if(x==1)
		return false;
	for(int i=0;i<primes.size() and primes[i]*primes[i] <= x;i++)
	{
		if(x % primes[i] == 0)
			return false;
	}
	return true;
}

void solve(lli a, lli b)
{
	for(lli i=a; i<=b; i++)
	{
		if(isprime(i))
			cout<<i<<"\n";
	}
	cout<<"\n";
}
int main()
{
	cin.sync_with_stdio(false);
	sieve();
	lli t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		solve(a, b);
	}
}