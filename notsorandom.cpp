#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define h(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	double a,b,c;
	int T,x,k,n,t;
	cin>>T;
	h(t,1,T+1)
	{
		cout<<"Case #"<<t<<": ";
		cin>>n>>x>>k>>a>>b>>c;
		double ans=0;
		h(i,0,(int)pow(2,2*n))
		{
			int j=i;
			double prob=1;
			int curval = x;
			h(e,0,n)
			{
				int lsb2 = j & 3;
				if(lsb2==3)
				{
					prob=0;
					curval=0;
					break;
				}
				else if(lsb2==0)
				{
					curval = curval & k;
					prob = prob*(a/100.0);
				}
				else if(lsb2==1)
				{
					curval = curval | k;
					prob = prob*(b/100.0);
				}
				else
				{
					curval = curval ^ k;
					prob = prob*(c/100.0);
				}
				j=j>>2;
			}
			ans += (prob*curval);
		}	
		printf("%0.10lf\n",ans);

	}
	
}