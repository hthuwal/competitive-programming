#include<iostream>
#define m 1000000007
using namespace std;
long long int mod(long long int a)
{
	return a%m;
}
int main()
{
	long long int n,x,i,j,ans;
	long long int freq[128]={0};
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		long long int temp[128]={0};
		for(j=0;j<128;j++)
		{
			if(freq[j]!=0)
			{
				temp[j^x]+=freq[j];	
			}
		}
		for(j=0;j<128;j++)
		{
			freq[j]+=temp[j];	
		}
		freq[x]+=1;
	}
	ans=0;
	for(i=0;i<=127;i++)
	{
		if(freq[i]>1)
		{
			ans+=mod(mod(mod(freq[i])*mod(freq[i]-1))*500000004);
			ans=mod(ans);
		}
	}
	cout<<mod(ans)<<endl;
}