/**
 * https://www.spoj.com/problems/MANGOES/
 * 
 * N boxes containing 
 * 1, 2, 3 .... N mangoes each
 * Box bi contains real mangoes if gcd of every pair in set (i, bi+1, bi+2) is 1
 * Find total number of real mangoes.
 * Assume N and N-1th box contain fake mangoes
 * 
 * Solution:
 * Consider n, n+1, n+2
 *      
 *      n, n+1 are coprime:
 *           if there exist a number 'd' that divides both of them.
 *           => 'd' divides  n+1 - 1 
 *           => 'd' divides 1
 *           => d = 1 therefore GCD of n, n+1 is 1
 *      
 *      Similarly n+1, n+2 are coprime:
 * 
 *      n, n+2:
 *          Let 'd' be a number that divides both of them.
 *          => 'd' divides n+2 - n
 *          => 'd' divides 2
 *          => there gcd can be 1 or 2
 *          => gcd won't be 2 if n and n+2 are not divisible by 2
 * 
 * Hence every odd box contains real mangoes.
 * Total number of real mangoes given N boxes is 
 * 
 * Sum of all odd numbers till N-2
 * 
 * For e.g. 1, 3, 5, 7, 9 (2*k-1) k = 5, Sum = k^2 (25)
**/
#include<bits/stdc++.h>
#define lli long long int
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    int t;
    cin>>t;
    lli N, n, k;
    while(t--)
    {
        cin>>N;
        n = N-2;
        if(n % 2 == 0)
            n -= 1;

        k = (n+1) / 2;
        cout<<(k*k)%N<<"\n";
    }
}