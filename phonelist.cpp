#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int t,n,i,flag;
	string hct,test;
	scanf("%d",&t);
	while(t--)
	{
		vector<string> hc;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			cin>>hct;
			hc.push_back(hct);
		}
		sort(hc.begin(),hc.end());
		for(i=0,flag=1;i<n-1;i++)
		{
			if(hc[i+1].find(hc[i])!=(string::npos))
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}