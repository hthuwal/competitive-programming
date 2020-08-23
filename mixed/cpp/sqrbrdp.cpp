	#include <iostream>
	#include <cstdio>
	#include <iomanip>
	using namespace std;
	long int calculate(long int a[],long int n)
	{
		/**
		 *  # n  be the length of bracket string 
		 *  # hc is a matrix column denotes current sum 0 to n/2 (at max left half of string is all '[')
		 *  # row denotes current place of bracket being considered
		 *  # when we have considered all the places (i.e current place is n+1) and cursum=0 then it 
		 *    is a valid bracket string.
		 */
		if(n==0)
			return 0;
		
		long int hc[n+2][(n/2)+2]={0};
		hc[n+1][0]=1;

		for(long int i=n;i>=1;i--)
		{
			for(long int cs=0;cs<=n/2;cs++)
			{
				if(a[i]==1)
					hc[i][cs]=hc[i+1][cs+1];
				else if(a[i]==-1)
				{
					if(cs-1<0)
						hc[i][cs]=0;
					else
						hc[i][cs]=hc[i+1][cs-1];
				}
				else
				{
					hc[i][cs]=hc[i+1][cs+1];
					if(cs-1>=0)
						hc[i][cs]+=hc[i+1][cs-1];
				}
			}
		}
		return hc[1][0];
	}
	int main()
	{
		#ifndef ONLINE_JUDGE
			freopen("in.txt","r",stdin);
		#endif
		long int t,n,k;
		cin>>t;
		while(t--)
		{
			long int a[40]={0};
			cin>>n>>k;
			for(long int i=0;i<k;i++)
			{
				long int s;
				cin>>s;
				a[s]=1;
			}
			cout<<calculate(a,2*n)<<endl;
		}

	}