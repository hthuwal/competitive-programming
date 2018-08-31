#include <iostream>
#include <cstdio>
using namespace std;
int calculate(int a[],int l,int n,int cursum)
{
	if(cursum<0)
	{
		return 0;
	}
	else if(l>n)
	{
		if(cursum==0)
			return 1;
		else
			return 0;
	}
	else if(a[l]==0)
	{
		int p = calculate(a,l+1,n,cursum+1);
		int q = calculate(a,l+1,n,cursum-1);
		return p+q;
	}
	else if(a[l]==-1)
	{
		return calculate(a,l+1,n,cursum-1);
	}
	else
	{
		return calculate(a,l+1,n,cursum+1);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t,n,k;
	cin>>t;
	while(t--)
	{
		int a[40]={0};
		cin>>n>>k;
		for(int i=0;i<k;i++)
		{
			int s;
			cin>>s;
			a[s]=1;
		}
		cout<<calculate(a,1,2*n,0)<<endl;
	}

}