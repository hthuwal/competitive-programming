#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string hc,jp;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>hc;
		jp=hc;
		reverse(jp.begin(),jp.end());
		if(hc==jp)
			cout<<"YES\n";
		else
			cout<<"NO\n";	
	}
}