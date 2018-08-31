#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000007
using namespace std;
int main()
{
	int hc	,n,m,c,i,hash1[2000],hash2[2000];
	scanf("%d %d %d",&n,&m,&c);
	memset(hash1,0,2000);
	memset(hash2,0,2000);
	for(i=0;i<n;i++)
	{
		scanf("%d",&hc);
		hash1[i]++;		
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&hc);
		hash2[i]++;
	}
	n>=m?n=n:n=m;
	for(i=1;i<1100;i++)
	{
		hash1[i]<=hash2[i]?hash1[i]=hash1[i]:hash1[i]=hash2[i];
	}

}