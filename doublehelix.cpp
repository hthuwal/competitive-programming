#include<iostream>
using namespace std;
int bsearch(int a[],int min,int max,int x)
{
    int m;
    while(min<=max)
    {
        m=(min+max)/2;
        if(a[m]==x)
            return m;
        else if(a[m]<x)
            min=m+1;
        else
            max=m-1;
    }
    return -1;
}
int main()
{
	int n,m,y,i,j,k,sum,hc[15000],jp[15000],hcsum[15000],jpsum[15000];
	while(1)
	{
 		cin>>n;
		if(n==0)
			break;
		else
		{
			hcsum[0]=0;
			jpsum[0]=0;
			for(i=1;i<=n;i++)
			{
				cin>>hc[i];
				hcsum[i]=hcsum[i-1]+hc[i];
			}
			cin>>m;
			for(i=1;i<=m;i++)
			{
				cin>>jp[i];
				jpsum[i]=jpsum[i-1]+jp[i];
			}
		for(i=1,j=0,k=0,sum=0;i<=n;i++)
		{
                y=bsearch(jp,1,m,hc[i]);
			if(y!=-1)
			{
				if((hcsum[i]-hcsum[j])>=(jpsum[y]-jpsum[k]))
				{
					sum+=(hcsum[i]-hcsum[j]);
				}
				else
				{
					sum+=(jpsum[y]-jpsum[k]);
				}
				k=y;
				j=i;
			}
		}
		if((hcsum[n]-hcsum[j])>=(jpsum[m]-jpsum[k]))
		{
			sum+=(hcsum[n]-hcsum[j]);
		}
		else
		{
			sum+=(jpsum[m]-jpsum[k]);
		}
		cout<<sum<<endl;
		}
	}
	return 0;
}
