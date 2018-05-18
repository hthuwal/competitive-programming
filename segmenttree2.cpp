//TO FIND MAX
#include <iostream>
#include <cstdio>
#include <cmath>
#define MAX 110000
using namespace std;

int lazy[MAX]={0};
int st[270000]={0};
int max(int a,int b)
{
	return (a>b?a:b);
}
int create(int arr[],int si,int l,int h)
{
	if(l==h)
	{
		st[si]=arr[l];
		return st[si];
	}
	int mid = (l+h)/2;
	st[si] = max(create(arr,2*si,l,mid),create(arr,2*si+1,mid+1,h));
	return st[si];
}
void update(int arr[],int si,int l,int h,int i,int x)
{
	if(i<l || i>h)
		return;
	st[si]=max(st[si],x);
	if(l!=h)
	{
		int mid=(l+h)/2;
		update(arr,2*si,l,mid,i,x);
		update(arr,2*si+1,mid+1,h,i,x);
	}
}
int getmax(int arr[],int si,int l,int h,int ql,int qh)
{
	if(ql<= l && qh >=h)
		return st[si];

	if(h< ql || l > qh)
		return 0;

	int mid=(l+h)/2;
	return max(getmax(arr,2*si,l,mid,ql,qh),getmax(arr,2*si+1,mid+1,h,ql,qh));
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n,a[MAX];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	create(a,1,0,n-1);
	for(int i=1;;i++)
	{
		if(st[i]==0)
			break;
		else
			cout<<st[i]<<" ";
	}
	update(a,1,0,n-1,0,7);
	cout<<"\n";
	for(int i=1;;i++)
	{
		if(st[i]==0)
			break;
		else
			cout<<st[i]<<" ";
	}
	cout<<endl<<getmax(a,1,0,n-1,1,3);
}