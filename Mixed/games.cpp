#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{

		string s;
		cin>>s;
		int f=0;
		int g=1;
		int flag=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='.')
				flag=1;
			if(s[i]<='9'&&s[i]>='0')
			{
				if(flag==1)
					g=g*10;
				f = f*10+s[i]-'0'; 
			}
		}
		f = gcd(f,g);
		cout<<g/f<<"\n";
	}
}