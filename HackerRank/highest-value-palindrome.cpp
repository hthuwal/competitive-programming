/**
 * https://www.hackerrank.com/challenges/richie-rich/problem
 */
#include <bits/stdc++.h>
using namespace std;
string ans(string s, int k)
{
	string orig(s);
	int l = s.length();

	// ensuring that it is atleast a palindrome
	for(int i=0, j=l-1; i<j; i++,j--)
	{
		if(s[i] != s[j])
		{
			if(k < 1)
				return "-1";
			int a = s[i] - '0';
			int b = s[j] - '0';
			if(a > b)
				s[j] = s[i];
			else
				s[i] = s[j];
			k--;
		}
	}

	// upgrading digits to '9' if possible	
	for(int i=0, j=l-1; i<=j; i++,j--)
	{
		if(k<1) // if no more operations left
			break;

		// if it isn't already 9
		if(s[i] != '9')
		{
			// if this was earlier changed to make it palindrome
			// or it is the central element of odd length palindrome
			if(s[i] != orig[i] or s[j] != orig[j] or i==j)
			{
				s[i] = s[j] = '9';
				k--; // count this as one operation
			}
			// else it will take two operations
			else if(k >= 2)
			{
				s[i] = s[j] = '9';
				k-=2;
			}
		}
	}
	return s;
}

int main()
{
	int n, k;
	string s;
	cin>>n>>k>>s;
	cout<<ans(s, k);
}