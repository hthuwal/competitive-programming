#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int prime[10005];
int sieve()
{
	int i,j;
	for(i=2;i<=100;i++)
	{
		if(!prime[i])
		{
			for(j=i*i;j<=10000;j+=i)
			{
				prime[j]=true;
			}
		}
	}
}
int breaknum(int a[],int n)
{
	int i=3;
	while(n>0)
	{
		a[i]=n%10;
		n=n/10;
		i--;
	}
}
int combine(int a[])
{
	int temp=a[0];
	for(int i=1;i<4;i++)
	{
		temp=temp*10+a[i];
	}
	return temp;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int i,num[4],dist[10005],j,a,b,temp;
		memset(dist,-1,sizeof(dist));
		sieve();
		cin>>a>>b;
		queue<int> hc;
		hc.push(a);
		dist[a]=0;
		while(!hc.empty()){
			int n = hc.front();
			hc.pop();
			for(i=3;i>=0;i--)
			{
				breaknum(num,n);
				for(j=0;j<=9;j++)
				{
					num[i]=j;
					temp = combine(num);
					if((!prime[temp]) && dist[temp]==-1 && temp>=1000)
					{
						dist[temp]=dist[n]+1;
						hc.push(temp);
					}
				}
			}
		}

		dist[b]==-1 ? cout<<"Impossible"<<endl : cout<<dist[b]<<endl;
	}
}
