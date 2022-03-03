/*
https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not/0
0. Ensure they have same length
1. Create a temp string and store concatenation of str1 to
       str1 in temp.
                          temp = str1.str1
2. If str2 is a substring of temp then str1 and str2 are 
   rotations of each other.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	for(cin>>t;t--;)
	{
		string str1, str2;
		cin>>str1>>str2;
		str1 = str1;
		if (str1.length() == str2.length() && (str1+str1).find(str2) != str1.npos)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
}