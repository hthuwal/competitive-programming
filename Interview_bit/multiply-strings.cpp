/**
 * Multiplying Strings
 *
 * https://www.interviewbit.com/problems/multiply-strings/
 * 
 * O(m*n) solution
 *
 * TLE
 */
#include<bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
    if(a.length() < b.length())
        swap(a, b);
    
    int carry = 0;
    string ans = "";
    int i = b.length()-1;
    int j = a.length()-1;
    for(; i>=0 and j>=0; i--,j--)
    {
        int s = (b[i]-'0') + (a[j]-'0') + carry;
        ans = (char)('0' + (s%10)) + ans;
        carry = (s/10);
    }

    while(j>=0)
    {
    	int s = (a[j]-'0') + carry;
    	ans = (char)('0' + (s%10)) + ans;
    	carry = (s/10);
    	j--;
    }
    
    while(carry > 0)
    {
    	ans = (char)('0' + (carry%10))+ans;
    	carry /= 10;
    }
    return ans;
}

string multiply(string a, string b)
{
	string ans = "0";
	int i = 0;
	for(;i<a.length();i++)
	{
		string temp = "";
		int j = b.length()-1;
		int carry = 0;
		for(; j>=0; j--)
		{
			int s = (b[j]-'0')*(a[i]-'0')+carry;
			temp = (char)('0'+(s%10)) + temp;
			carry = (s/10);
		}
		while(carry > 0)
		{
			temp = (char)('0' + (carry%10))+temp;
			carry /= 10;
		}
		ans = add(ans+"0", temp);
	}

	for(i=0;i<ans.length();i++)
		if(ans[i]!='0')
			break;

	ans = ans.substr(i);
	if(ans.length()==0)
		return "0";
	else
		return ans;
}
int main()
{
	string a, b;
	cin>>a>>b;
	cout<<multiply(a,b);
}
