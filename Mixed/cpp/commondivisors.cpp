#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
int a[1100000],shift;	
void sieve()
{
	int i,j;
	for(i=2;i<1100000;i++)
		a[i]=1;
	for(i = 2;i<=sqrt(1100000);i++)
	{
		if(a[i]==1)
		{
			for(j=i*i;j<1100000;j+=i)
			{
				a[j]=0;
			}
		}
	}
}
int binarygcd(int a,int b)
{
	shift=0;
	if(a==0)return b;
	if(b==0)return a;
	for(shift=0;((a|b)&1)==0;shift++)
	{
		a>>=1;
		b>>=1;
	}
	while((a&1)==0)
		a>>=1;

	do{
		while((b&1)==0)
			b>>=1;

		if(a>b)
		{
			int t = a;
			a=b;
			b=t;
		}
		b=b-a;
	}while(b!=0);

	return a;
}
int main()
{
	sieve();
	int i,p,ans,t,u,count,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&u,&v);
		p=binarygcd(u,v);
		ans=(shift+1);
		for(i=3;i<=p	;i++)
		{
			if(a[i]==1)
			{
				count=0;
				while(p%i==0)
				{
					p=p/i;
					count++;
				}
				ans=ans*(count+1);
			}
		}
		printf("%d\n",ans);
	}
}