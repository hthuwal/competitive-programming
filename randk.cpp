#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int ans,t;	
	cin>>t;
	string hc;
	while(t--)
	{
		cin>>hc;
		int min_so_far=0;
		int min_ending_here=0;
		int k,i=0,j=0;
		for(k=0;k<hc.length();k++)
		{
			if(hc[k]=='R')
				min_ending_here+=1;
			else if(hc[k]=='K')
				min_ending_here-=1;
			if(min_ending_here)
		}
		if(min_so_far==0)

		for(k=0,ans=0;k<hc.length();k++)
		{
			if((k<=i||k>j)&&hc[k]=='R')
				ans++;
		}
		cout<<ans+abs(min_so_far)<<endl;
	}
  
}
