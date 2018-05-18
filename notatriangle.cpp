#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int hc[4410000];
int a[2100];
int bsearch(int a[],int l,int h,int x)
{
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(l==h && a[mid]>x)
		{
			return l;
		}
		else if(l==h && a[mid]<=x)
		{
			return -1;
		}
		if(a[mid]<=x)		
		{
			l=mid+1;
		}
		else
		{
			h=mid;
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	while(1)
	{
		int n,ans=0;;
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		//cout<<bsearch(a,0,n-1,12);
		int k=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				hc[k]=a[i]+a[j];
				k++;
			}
		}
		for(int i=0;i<k;i++)
		{
			int j = bsearch(a,0,n,hc[i]);
			if(j!=-1)
			{
				ans+=(n-j);
			}
		}
		printf("%d\n",ans);
	}
}
