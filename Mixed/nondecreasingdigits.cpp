#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	long long int a[70][11]={0};
	/**
	 * initializing 0 length ending with any digit =0;
	 * initializing 1 length endignth wiht any digit=1;
	 */
	for(int j=0;j<=9;j++)
	{
		a[0][j]=0;
		a[1][j]=1;
	}
	/**
	 * lenght i ending with digit j = summation of length i-1 ending with digit k sucht that 0<=k<=j
	 */
	for(int i=1;i<70;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=j;k++)
			{
				a[i][j]+=a[i-1][k];
			}
		}
	}
	/**
	 * accumulating result for length i
	 * total for length i = summation of lenght i ending with j 0<=j<=9
	 */
	for(int i=1;i<=70;i++)
	{
		a[i][10]=0;
		for(int j=0;j<=9;j++)
		{
			a[i][10]+=a[i][j];
		}
	}
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>i;
		cin>>n;
		cout<<i<<" "<<a[n][10]<<"\n";
	}
}