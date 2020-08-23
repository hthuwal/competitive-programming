#include<iostream>
using namespace std;
int final(int w[],int c,int n)
{
	int max = -1,i;
	for(i=0;i<=c;i++)
	{	
		if(w[i]>max)
		{
			if((i<n && n-c>=1)||i==n)
			{
				max=w[i];
			}
		}
	}	
	return max;
}
int main()
{
	int t,n,i,w[10000],count;
	string chef,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>ans;
		cin>>chef;
		for(i=0;i<=n;i++)
		{
			cin>>w[i];
		}
		for(i=0,count=0;i<n;i++)
		{
			if(ans[i]==chef[i])
				count++;
		}
		cout<<final(w,count,n)<<endl;
	}
	return 0;
}