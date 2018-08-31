#include <cstdio>
int main()
{
	freopen("in.txt","r",stdin);
	int t,q,u,l,r,val,n,index;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		int a[n]={0};
		for(scanf("%d",&u);u--;)
		{
			scanf("%d %d %d",&l,&r,&val);
			a[l]=a[l]+val;
			if(r!=n-1)
				a[r+1]=a[r+1]-val;
		}
		for(int i=1;i<n;i++)
			a[i]=a[i]+a[i-1];

		for(scanf("%d",&q);q--;)
		{
			scanf("%d",&index);
			printf("%d\n",a[index]);
		}
	}	
}