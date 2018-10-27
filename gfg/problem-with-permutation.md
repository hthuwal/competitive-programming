### [Rank The Permutations](Rank The Permutations)

Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Return 0 if the characters are repeated in the string.

[Reference](https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/)


#### CPP O(n) solution

```cpp
#include<bits/stdc++.h>
#define M 1000003
using namespace std;
int fact[17];

void factorials()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<17;i++)
        fact[i]=(i*fact[i-1]) % M;
}
int get_ans(string s)
{
    int l = s.length();
    
    // stores which character occurs in string how many times;
    int hc_hash[26] ={0} ;
    
    for(int i=0;i<l;i++)
        hc_hash[s[i]-'a']++;
     
    // check if any character is repeated(return 0 if true as per question)
    for(int i=0;i<26;i++)
        if(hc_hash[i] > 1)
            return 0;
            
    // now hc_hash[i] stores how many characters <= 'a'+i occur in string
    for(int i=1;i<26;i++)
        hc_hash[i] += hc_hash[i-1]; 
        
    int ans = 1;
    for(int i=0;i<l;i++)        
    {
        int num_char_smaller_in_right = (s[i] == 'a') ? 0: hc_hash[s[i]-'a'-1];

        // ans += num_char_smaller_in_right that can replace me x k! where
        // k is the length of the string remaining after me
        ans = (ans + (num_char_smaller_in_right * (fact[l-i-1])) % M) % M;
        
        // this character shouldn't be counted in right of next character
        for(int j=s[i]-'a'; j<26;j++)
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