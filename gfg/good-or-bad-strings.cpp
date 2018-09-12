/*
https://practice.geeksforgeeks.org/problems/good-or-bad-string/0
 */

#include<bits/stdc++.h>
using namespace std;

bool isvowel(char a)
{
    if(a == 'a' || a == 'i' || a == 'o' || a == 'e' || a == 'u')
        return true;
    return false;
}

int main()
{
	int t,n;
	string str;
	
	for(cin>>t;t--;)
	{
	    cin>>str;
	    bool bad=false;
	    int cons=0;
	    int vowels=0;
	    for(int i=0;i<str.length();i++)
	    {
	        if(str[i] == '?')
	        {
	            vowels++;
	            cons++;
	        }
	        else if(isvowel(str[i]))
	        {
	            vowels ++;
	            cons = 0;
	        }
	        else{
	            cons++;
	            vowels = 0;
	        }

	        if(vowels > 5 || cons > 3)
	        {
	            bad=true;
	            break;
	        }
	    }
	    if(bad)
	        cout<<0<<endl;
	    else
	        cout<<1<<endl;
	}
}