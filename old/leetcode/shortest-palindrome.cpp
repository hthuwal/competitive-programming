/**
 * Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. 
 * Find and return the shortest palindrome you can find by performing this transformation.
 *
 * https://leetcode.com/problems/shortest-palindrome/
 */

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

/**
 * LPS array of KMP
 */
vi get_lps(string s)
{
    int k=0;
    vi pi(s.length(), 0);

    for(int i=1;i<s.length();i++)
    {
       while(k>0 and s[k] != s[i])
            k = pi[k-1];
       if(s[k] == s[i])
           k++;
       pi[i] = k;
    }
    return pi;
}

/**
 * lps of( s + "$" + rev(s))
 * the s[lps[-1]:]+s is the ans
 */
string shortestPalindrome(string s) {
    
    if(s.length() == 0)
        return s;
    string reve = string(s.rbegin(), s.rend());
    string trick = s + "#" + reve;
    vi lps = get_lps(trick);
    string additon = s.substr(*lps.rbegin());
    return string(additon.rbegin(), additon.rend()) + s;

}

int main()
{
	cout<<shortestPalindrome("aacecaaa");
}