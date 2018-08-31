#include<bits/stdc++.h>
using namespace std;
int reverse(int n)
{
	int m=0;
	while(n!=0)
	{
		m=m*10+n%10;
		n=n/10;
	}
	return m;
}
int check(int n)
{
	int m = reverse(n);
	if(n-m==0)
		return 1;
	else 
		return 0;
}
int main()
{
	int t,l,r,i,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&l,&r);
		for(i=l,sum=0;i<=r;i++)
		{
			if(check(i))
				sum+=i;
		}
		printf("%d\n",sum);
	}
	return 0;
}