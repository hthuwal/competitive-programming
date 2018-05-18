#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif

	while(1)
	{
		int n;
		cin>>n;
		int a[1500];
		if(n==0)
			break;
		else 
		{
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
			sort(a,a+n);
			int flag=1;
			for(int i=1;i<n;i++)
			{
				if(a[i]-a[i-1]>200)
				{
					flag=0;
					break;
				}
			}
			if(flag==0)
				cout<<"IMPOSSIBLE"<<endl;
			else
			{
				if((1422-a[n-1])*2<=200)
					cout<<"POSSIBLE"<<endl;
				else
					cout<<"IMPOSSIBLE"<<endl;
			}
		}
	}
}