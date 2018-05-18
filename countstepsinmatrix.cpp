#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int hc[255000],jp[255000],i,j,t,n,ans,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a);
				hc[a]=i;
				jp[a]=j;
			}
		}
		for(i=2;i<=n*n;i++)
		{
			ans+=(abs(hc[i]-hc[i-1])+abs(jp[i]-jp[i-1]));
		}
		printf("%d\n",ans);
	}
	return 0;
}