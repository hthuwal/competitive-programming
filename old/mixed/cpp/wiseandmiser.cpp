#include<cstdio>
#include<iostream>
using namespace std;
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int i,j,ans,n,m,a[110][110];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<m;j++)
		{
			if(j==0)
			{
				a[i][j]+=min(a[i+1][j],a[i+1][j+1]);
			}
			else if(j==m-1)
			{
				a[i][j]+=min(a[i+1][j-1],a[i+1][j]);
			}
			else
				a[i][j]+=min(a[i+1][j-1],min(a[i+1][j],a[i+1][j+1]));
		}
	}
	for(i=0,ans=1000000;i<m;i++)
		if(a[0][i]<ans)
			ans=a[0][i];

	printf("%d",ans);
}