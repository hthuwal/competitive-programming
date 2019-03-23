/**
 * HackerEarth
 *
 * https://www.hackerearth.com/challenges/competitive/march-circuits-19/algorithm/does-it-divide-3c60b8fb/
 *
 * Find if n! is perfectley divisible by sum of 1 to n?
 * 	Or
 * is n! % ( n * (n+1) / 2) == 0 or not?
 *
 * n <= 10^9
 * 100 test cases
 *
 * obviously n! will overflow (23! is O(10^19)) for n > 23 in C++, python gives TLE
 *
 * Solution:
 * 	Expression can be re written as is [ 2 * (n-1)! ] divisible by (n+1)
 *
 * 	Find Prime Factorization of n+1. = say p1^a1, p2^a2 etc.
 *
 *  Find the highest power of all prime factors (say p1) that divides 2 * (n-1)! using legendre's formula.
 *  If that is less than a1 => (n+1) will not divide numerator perfectly 
 */

#include<bits/stdc++.h>
#define lli long long int
using namespace std;

bool sieve[31640] = {0};
vector<int> primes;

/**
 * Using Sieve of Eratosthenes to find all primes
 * upto sqrt(10^9).
 *
 * Constant time = O(31640)
 */
void preprocess()
{
	primes.push_back(2);
	for(int i=3; i<31640; i+=2)
	{
		if(sieve[i] == 0)
		{
			primes.push_back(i);
			for(int j=i+i; j<31640; j+=i)
				sieve[j] = 1;
		}
	}
}

/**
 * Find Prime Factorization of n.
 */
vector<pair<int, int> > prime_factorization(int n)
{
	vector<pair<int, int> > ans;
	for(int i=0;i<primes.size() and n!=1; i++)
	{
		int count = 0;
		while( n % primes[i] == 0)
		{
			n /= primes[i];
			count ++;
		}
		if(count != 0)
			ans.push_back({primes[i], count});
	}
	if(n != 1)
		ans.push_back({n, 1});
	return ans;
}

/** 
 * Returns highest power of prime p that divides x!
 */
lli highest_power_of_p(lli p, lli x)
{
	lli ans = 0;

	// Calculate ans = x/p + x/(p^2) + x/(p^3) + .... 
	while(x)
	{
		x/=p;
		ans+=x;
	}
	return ans;
}

int main()
{
	cin.sync_with_stdio(false);
	preprocess();
	lli t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<pair<int, int>> factors = prime_factorization(n+1);
		bool possible = true;
		for(auto factor: factors)
		{
			lli p = factor.first;
			lli power = factor.second;

			if( p == 2)
				power--;

			lli hpp = highest_power_of_p(p, n-1);
			if(hpp < power)
			{
				possible = false;
				break;
			}

		}
		if(possible)
			cout<<"YES"<<"\n";
		else
			cout<<"NO"<<"\n";
	}

}