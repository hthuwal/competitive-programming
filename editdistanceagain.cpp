#include <iostream>
#include <cstdio>
using  namespace std;

int min(int a,int b)
{
	return a<b?a:b;
}
int editdistance(string a)
{
	int n = a.length();
	if(n==1)
		return 0;
	else
	{
		int d1,d2;
		d1=d2=0;
		for(int i=0;i<n;i+=2)
		{
			if(a[i]<='z' && a[i]>='a')
				d1++;
			if(i!=n-1)
			{
				if(a[i+1]>='A' && a[i+1]<='Z')
					d1++;
			}
		}
		for(int i=0;i<n;i+=2)
		{
			if(a[i]<='Z' && a[i]>='A')
				d2++;
			if(i!=n-1)
			{
				if(a[i+1]>='a' && a[i+1]<='z')
					d2++;
			}
		}
		return min(d1,d2);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string p;
	while(cin>>p)
	{
		cout<<editdistance(p)<<"\n";
	}
}
