### Rank The Permutations

[GFG](https://practice.geeksforgeeks.org/problems/rank-the-permutations/0), [Interviewbit](https://www.interviewbit.com/problems/sorted-permutation-rank/)

Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Return 0 if the characters are repeated in the string.

[Reference](https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/)


#### CPP O(n) solution

```cpp
#include<bits/stdc++.h>
#define M 1000003
using namespace std;
int fact[17];

void factorials(int fact[], int n)
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<n+1;i++)
        fact[i]=(i*fact[i-1]) % M;
}
int get_ans(string s)
{
    int l = s.length();
    int fact[l+5];
    factorials(fact, l+1);
    // stores which character occurs in string how many times (work for all the ascii characters);
    int hc_hash[256] ={0} ;
    
    for(int i=0;i<l;i++)
        hc_hash[s[i]]++;
    
    // check if characters repeated
    for(int i=0;i<26;i++)
        if(hc_hash[i] > 1)
            return 0;

    // now hc_hash[i] stores how many characters <= 'a'+i occur in string
    for(int i=1;i<256;i++)
        hc_hash[i] += hc_hash[i-1]; 
    
    int ans = 1;
    for(int i=0;i<l;i++)        
    {
        int num_char_smaller_in_right = hc_hash[s[i]-1];

        // ans += num_char_smaller_in_right that can replace me x k! where
        // k is the length of the string remaining after me
        ans = (ans + (num_char_smaller_in_right * (fact[l-i-1])) % M) % M;
        
        // this character shouldn't be counted in right of next character
        for(int j=s[i]; j<256;j++)
            hc_hash[j]--;
    }
    return ans;
}

int main()
{
    int t;
    string s;
    cin>>t;
    factorials();
    while(t--)
    {
        cin>>s;
        cout<<get_ans(s)<<"\n";
    }
    return 0;
}
```