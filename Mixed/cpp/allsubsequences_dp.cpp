/*
Let countSub(n) be count of subsequences of 
first n characters in input string. We can
recursively write it as below. 

countSub(n) = 2*Count(n-1) - Repetition

If current character, i.e., str[n-1] of str has
not appeared before, then 
   Repetition = 0

Else:
   Repetition  =  Count(m)
   Here m is index of previous occurrence of
   current character. We basically remove all
   counts ending with previous occurrence of
   current character.

How does this work?
If there are no repetitions, then count becomes double 
of count for n-1 because we get count(n-1) more 
subsequences by adding current character at the end of 
all subsequences possible with n-1 length.
If there repetitions, then we find count of all distinct
 subsequences ending with previous occurrence. This count
  can be obtained be recursively calling for index of previous occurrence.
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#define mod 1000000007
using namespace std;

int main()
{
    int t,n,last[26];

    string s;
    freopen("in.txt","rb",stdin);
    for(scanf("%d",&t);t--;)
    {
        cin>>s;
        n = s.length();
        
        memset(last,-1,26*sizeof(int));
        
        long long int dp[n+1];  

        dp[0]=1;//empty substring has only 1 subsequences

        // Traverse through all lengths from 1 to n.
        for(int i=1;i<=n;i++)
        {
            char c = s[i-1];
            if(c<='z' && c>='a')
                c=c-'a'+'A';
            // Number of subsequences with substring
            // str[0..i-1]
            dp[i]=(2*dp[i-1]) % mod;

            // If current character has appeared
            // before, then remove all subsequences
            // ending with previous occurrence.
            if (last[c-'A'] != -1)
                dp[i] = (dp[i] - dp[last[c-'A']]+mod)%mod; // adding mod to if subtraction becomes negative

            last[c-'A']=i-1;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}