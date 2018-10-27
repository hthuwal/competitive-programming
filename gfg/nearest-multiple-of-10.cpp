/**
 * Given a positive number N. The task is to round N to nearest multiple of 10. 
 * Number can be so big and can contains 1000 of digits.
 *
 * https://practice.geeksforgeeks.org/problems/nearest-multiple-of-10/0
 */

#include<bits/stdc++.h>
using namespace std;

string sceil(string s)
{
	int n = s.length();

	s[n-1] = '0';
	int carry = 1;
	for(n = n-2; n>=0 and carry != 0; n--)
	{
		int d = s[n]-'0' + carry;
		if(d < 10)
		{
			s[n] = '0' + d;
			carry = 0;
		}
		else
			s[n] = '0';
	}
	if(carry == 1)
		s = '1'+s;
	return s;
}

int main()
{
	int t;
	cin>>t;
	string s;

	while(t--)
	{
		cin>>s;
		int n = s.length();
		if(s[n-1] == 0)
			continue;

		if(s[n-1] <= '5')
			s[n-1] = '0';
		else
			s = sceil(s);

		cout<<s<<"\n";
	}

}