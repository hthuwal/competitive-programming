#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,m,c,ans;
	cin>>n;
	while(n--)
	{

		cin>>m;
		if(m%2==1)
			cout<<m<<"\n";
		else
		{
			ans=0;
			while(m!=0)
			{
				c=m&1;
				ans=(ans<<1)|c;
				m=m>>1;
			}
			cout<<ans<<"\n";
		}
	}
	
}	