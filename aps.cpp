#include <iostream>
#include <cstdio>
using namespace std;
long long int a[10000009];//to hold prime numbers using sieve
long long int b[10000009];//to hold lowest prime factor of i they get divided by 
long long int c[10000009];//to hold the sequence

/**
 * generate prime upto 10000009
 * while generating save lowest prime divisior 
 */
void sieve()
{
	for(long long int i=0;i<10000009;i++)
	{
		a[i]=i;
		b[i]=0;
	}
	for(long long int i=2;i<10000009;i++)
	{
		if(a[i]!=0)
		{
			b[i]=i;
			for(long long int j=i+i;j<10000009;j=j+i)
			{
				if(a[j]!=0)//only those j's which havent been divided by any prime yet
				{
					a[j]=0;
					b[j]=i;// all j's can be divided by i
				}
			}
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	sieve();
	c[0]=0;
	c[1]=0;
	for(long long int i=2;i<10000009;i++)
	{
		c[i]=c[i-1]+b[i];
	}
	long long int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<c[n]<<"\n";
	}
}