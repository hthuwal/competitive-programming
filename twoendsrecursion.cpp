#include <iostream>
#include <cstdio>
using namespace std;
struct score{
	int p1;
	int p2;
};
score evaluate(int a[],int l,int h,int p)
{
	score zero;
	zero.p1=0;
	zero.p2=0;
	if(l<=h)
	{
		if(p==1)
		{
			score c1 = evaluate(a,l+1,h,2);
			score c2 = evaluate(a,l,h-1,2);
			c1.p1+=a[l];
			c2.p1+=a[h];
			if((c1.p1-c1.p2)>(c2.p1-c2.p2))
				return c1;
			else if((c1.p1-c1.p2)<(c2.p1-c2.p2))
				return c2;
			else 
			{
				if(c1.p2<c2.p2)
					return c1;
				else 
					return c2;
			}
		}
		else if(p==2)
		{
			score c;
			if(a[l]>=a[h])
			{
				c = evaluate(a,l+1,h,1);
				c.p2+=a[l];
			}
			else
			{
				c = evaluate(a,l,h-1,1);
				c.p2+=a[h];
			}
			return c;
		}
	}
	else
		return zero;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
    int t,a[1100],n,count=0;
    score final;
    while(1)
    {
    	count++;
	    cin>>n;
	    if(n==0)
	    	break;
	    for(int i=0;i<n;i++)
	    {
	    	cin>>a[i];
	    }
	    final = evaluate(a,0,n-1,1);
	    n = final.p1-final.p2;
	    cout<<"In game "<<count<<",the greedy strategy might lose by as many as "<<n<<" points.\n";
    }
    
}