/**
 * observe pattern
 */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	long int t,n;
	cin>>t;
	while(t--)
	{
		long int n;
		cin>>n;
		long int b = floor(log2(n+2))-1;//
		long int c = floor(pow(2,b+1))-2+1;
		if(n!=c-1)
			b++; 
		c=n-c;
		string out="";
		long int x;
		for(int i=0;i<b;i++)
		{
			x = c&1;
			if(x==0)
				out="5"+out;
			else
				out="6"+out;
			c=c>>1;
		}
		cout<<out<<endl;
	}
}
