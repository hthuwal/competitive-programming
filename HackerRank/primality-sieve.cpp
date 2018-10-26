/**
 * https://www.hackerrank.com/challenges/ctci-big-o/problem
 * 
 *  Given  integers, determine the primality of each integer 
 *  and print whether it is Prime or Not prime on a new line.
 *
 * p<=10^9
 *
 * Using Sieve
 * Each Query N: 
 *     Time: O(sqrt(N)), o(number of primes <= sqrt(N))
 */
#include <bits/stdc++.h>
using namespace std;

bool sieve[31640]={0};
vector<int> primes;

void preprocess()
{
    primes.push_back(2);
    for(int i=3; i<31640; i+=2)
    {
        if(sieve[i] == 0)
        {
            primes.push_back(i);
            for(int j=i+i;j<31640;j+=i)
                sieve[j] = 1;
        }
    }
}


string primality(int n) {
    if(n<=1)
        return "Not prime"; 
    for(int i=0;i<primes.size() and primes[i]*primes[i] <= n; i++)
    {
        if(n == primes[i])
            return "Prime";
        else if(n%primes[i] == 0)
            return "Not prime"; 
    }
    return "Prime";
}

int main()
{
    preprocess();
    int t, n;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        cout<<primality(n)<<"\n";
    }
}
