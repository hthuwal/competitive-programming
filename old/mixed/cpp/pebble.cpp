#include <iostream>
#include <cstdio>
using namespace std;
int aadi(string hc)
{
	int count=0;
	char c='1';
	for(int i=0;i<hc.length();i++)
	{
		if(count%2==0)
			c='1';
		else 
			c='0';
		if(hc[i]==c)
			count++;
	}
	return count;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string hc;
	int t=0;
	while(cin>>hc)
	{	
			t++;
			cout<<"Game #"<<t<<": "<<aadi(hc)<<"\n";
	}
}