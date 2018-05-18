#include<iostream>
#define x 1000000007
using namespace std;
int main()
{
	int i,t,n,k,cur;
	cin>>t>>n;
	int a[1000000]={0};
	int b[1000000]={0};
	a[0]=1;	
	for(i=1;i<=n;i++)
	{
		if(i-2>=0)
		{
			a[i]=((a[i]%x)+(a[i-2]%x))%x;
		}
		if(i-5>=0)
		{
			a[i]=((a[i]%x)+(a[i-5]%x))%x;
		}
	}
	while(t--)
	{
		cin>>cur>>k;
		if(cur<k || k==2 ||k==5)
			cout<<a[cur]<<endl;
		else if(cur==k)
		{
			cout<<(a[cur]+1)%x<<endl;
		}
		else
		{
			for(i=0;i<=k;i++)
				b[i]=a[i];
			
			b[k]=(b[k]+1)%x;

			for(i=k+1;i<=cur;i++)
			{
				if(i-2>=0)
				{
					b[i]=((b[i]%x)+(b[i-2]%x))%x;
				}
				if(i-5>=0)
				{
					b[i]=((b[i]%x)+(b[i-5]%x))%x;
				}
				if(i-k>=0)
				{
					b[i]=((b[i]%x)+(b[i-k]%x))%x;
				}
			}	
			cout<<b[cur]<<endl;		
		}
	}
}