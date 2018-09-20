/*
https://www.hackerrank.com/challenges/abbr/

You can perform the following operations on the string, a:

1. Capitalize zero or more of a's lowercase letters.
2. Delete all of the remaining lowercase letters in .a

Given two strings, a and b, determine if it's possible to make  
a equal to b as described. 
If so, print YES on a new line. Otherwise, print NO.
*/

#include<bits/stdc++.h>
using namespace std;

bool solve(string a, string b)
{
	int n = a.length();
	int m = b.length();

	/*
	dp[i][j] denotes whether it is possible to convert
	a[0:i-1] to a[0:j-1] (closed bounds)	
	*/
	bool dp[n+1][m+1];
	
	// if a and b are both empty then it is possible
	dp[0][0] = true; 

	/*
	if b is empty, them it is it is possible to convert a[0:i-1] to b 
	only if a[i-1] is a lowercase letter (can be ignored) and it is possible t convert a[0:i-2] to b
	that is all letters in a[0:i-1] should be lower case
	 */
	for(int i=1; i<=n; i++)
		dp[i][0] = islower(a[i-1]) && dp[i-1][0];

	// if a is empty and b is non empty, it is not possible to convert any a[0:i-1] to b
	for(int i=1; i<=m; i++)
		dp[0][i] = false;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			// its not possible if length of a[0:i-1] is less than b[0:j-1]
			if(i<j)
				dp[i][j] = false;

			// if the last letter of a[0:i-1] is lowercase
			else if(islower(a[i-1]))
			{
				// possibility 1: this would be deleted
				// then it must be possible to convert a[0:i-2] to b[0:j-1]
				bool path1 = dp[i-1][j]; 

				// possibility 2: if uppercase form of last character of a[0:i-1] is equal to last character of b[0:j-1], 
				// then we can convert it to uppercase
				bool path2 = (toupper(a[i-1]) == b[j-1]) && dp[i-1][j-1];

				// either of the two possibility is valid
				dp[i][j] = path1 | path2;
			}

			// if the last letter of a[0:i-1] is upper case
			else{

				// if last letter of a[0:i-1] equal to last letter of b[0:j-1]
				// then only one possiblity to convert a[0:i-2] to b[0:j-2] because we can't remove upper case letters
				if(a[i-1] == b[j-1])
					dp[i][j] = dp[i-1][j-1];
				// if last letter of a[0:i-1] not equal to last letter of b[0:j-1]
				// then its not possible because we can't ignore a uppercase letter
				else
					dp[i][j] = false;
			}
		}	
	}		
	return dp[n][m];
}

int main()
{
	string a, b;
	int q;
	for(cin>>q; q--;)
	{
		cin>>a>>b;
	    if(solve(a, b))
	   		cout<<"YES\n";
	   	else
	   		cout<<"NO\n";
	}

}