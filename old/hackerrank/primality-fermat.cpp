/**
 * https://www.hackerrank.com/challenges/ctci-big-o/problem
 * 
 *  Given  integers, determine the primality of each integer 
 *  and print whether it is Prime or Not prime on a new line.
 *
 * p<=10^9
 *
 * Using Fermat's little theorem
 * Each Query N: 
 *     Time: O(log(N))
 */
#include <bits/stdc++.h>
using namespace std;

// O(log b)
long modulo_exp(long a, long b, long m)
{
    long ans = 1;
    a = a % m;
    while(b>0)
    {
        if(b & 1)
            ans = (ans * a) % m;
        
        a = (a*a)%m;
        b = b >> 1;
    }
    return ans;
}

string isprime_fermat(long p, int iter)
{
    if(p==1)
        return "Not prime";
    for(int i=0;i<iter;i++)
    {
        long a = random() % (p-1) + 1; // a randome number from 1 to p-1
        if(modulo_exp(a, p-1, p)  != 1)
            return "Not prime";
    }
    return "Prime";
}

int main()
{
    int t, n;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        cout<<isprime_fermat(n, 10)<<"\n";
    }
}
