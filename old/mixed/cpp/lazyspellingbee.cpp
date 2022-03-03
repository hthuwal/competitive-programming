#include <iostream>
#include <cstdio>
#define f(i,a,b) for(int i=a;i<b;i++)
#define mul(a,b) ((a%MOD)*(b%MOD))%MOD
#define MOD 1000000007
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	string hc;
	f(i,1,t+1)
	{
		cin>>hc;
		cout<<"Case #"<<i<<": ";
		int n = hc.length();
		long long int ans=1;
		if(n!=1)
		{
			f(i,0,n)
			{
				if(i==0)
				{
					if(hc[i]!=hc[i+1])
						ans=mul(ans,2);
				}
				else if(i==n-1)
				{
					if(hc[i-1]!=hc[i])
						ans=mul(ans,2);
				}
				else
				{
					if(hc[i]==hc[i-1])
					{
						if(hc[i]!=hc[i+1])
							ans=mul(ans,2);			
					}
					else if(hc[i]==hc[i+1])
					{
						if(hc[i]!=hc[i-1])
							ans=mul(ans,2);		
					}
					else if(hc[i-1]==hc[i+1])
					{
						if(hc[i-1]!=hc[i])
							ans=mul(ans,2);		
					}
					else
					{
						ans=mul(ans,3);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}