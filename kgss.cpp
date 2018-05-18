//TO FIND MAX
#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#define MAX 110000
using namespace std;

struct triplet{
	int sum;//max sum of a[i] & a[j]
	int max1;//index of maximum
	int max2;//index of second maximum
};

int arr[MAX]={0};
triplet st[270000];

int max(int a,int b)
{
	return (arr[a]>arr[b]?a:b);
}
triplet create(int si,int l,int h)
{
	if(l==h)
	{
		st[si].max1=l;
		st[si].sum=st[si].max2=0;
		return st[si];
	}
	else
	{
		int mid=(l+h)/2;
		triplet lefthalf = create(2*si,l,mid);
		triplet righthalf = create(2*si+1,mid+1,h);

		if(arr[lefthalf.max1] > arr[righthalf.max1])
		{
			st[si].max1 = lefthalf.max1;
			st[si].max2 = max(lefthalf.max2,righthalf.max1);
		}
		else
		{
			st[si].max1 = righthalf.max1;
			st[si].max2 = max(righthalf.max2,lefthalf.max1);
		}
		st[si].sum = arr[st[si].max1]+arr[st[si].max2];
		return st[si];
	}
}
triplet update(int si,int l,int h,int i, int x)
{
	triplet temp;
	temp.sum=temp.max1=temp.max2=0;
	if(i<l || i>h)
		return st[si];
	if(l==h)
	{
		st[si].max1=l;
		st[si].sum=st[si].max2=0;
		return st[si];
	}
	if(l!=h)
	{
		int mid=(l+h)/2;
		triplet lefthalf = update(2*si,l,mid,i,x);
		triplet righthalf = update(2*si+1,mid+1,h,i,x);

		if(arr[lefthalf.max1] > arr[righthalf.max1])
		{
			st[si].max1 = lefthalf.max1;
			st[si].max2 = max(lefthalf.max2,righthalf.max1);
		}
		else
		{
			st[si].max1 = righthalf.max1;
			st[si].max2 = max(righthalf.max2,lefthalf.max1);
		}
		st[si].sum = arr[st[si].max1]+arr[st[si].max2];
		return st[si];
	}
}
triplet getmaxsum(int si,int l,int h,int ql,int qh)
{
	if(ql<=l && qh>=h)
		return st[si];
	triplet temp;
	temp.max1=temp.max2=temp.sum=0;
	if(ql>h || qh<l)
		return temp;
	else
	{
		int mid=(l+h)/2,max1,max2;
		triplet lefthalf = getmaxsum(2*si,l,mid,ql,qh);
		triplet righthalf = getmaxsum(2*si+1,mid+1,h,ql,qh);

		if(arr[lefthalf.max1] > arr[righthalf.max1])
		{
			max1 = lefthalf.max1;
			max2 = max(lefthalf.max2,righthalf.max1);
		}
		else
		{
			max1 = righthalf.max1;
			max2 = max(righthalf.max2,lefthalf.max1);
		}
		triplet temp = {arr[max1]+arr[max2],max1,max2};
		return temp;
	}

}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	create(1,1,n);

	cin>>q;
	for(int i=0;i<q;i++)
	{
		int u,v;
		char c;
		cin>>c>>u>>v;
		if(c=='U')
		{	
			arr[u]=v;
			update(1,1,n,u,v);
			
		}
		else if(c=='Q')
		{
			triplet hc= getmaxsum(1,1,n,u,v);
			cout<<hc.sum<<"\n";
		}
	}
}
