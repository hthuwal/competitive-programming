#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lcp(string a, string b)
{
	int i,count,n = a.length();
	for(i=0,count=0;i<n;i++)
	{
		if(a[i]==b[i])
			count++;
		else
			break;
	}
	return count;
}

int main()
{
	int t,n,i,ans;
	string hc;
	vector<string> aadi;
	scanf("%d",&t);
	while(t--)
	{
		cin>>hc;
		aadi.clear();
		n=hc.length();
		for(i=0;i<n;i++)
		{
			aadi.push_back(hc.substr(i));
		}
		sort(aadi.begin(),aadi.end());
		ans=(aadi[0].length());		
		n=aadi.size();
		for(i=0;i<n-1;i++)
		{
			ans+=(aadi[i+1].length()-lcp(aadi[i],aadi[i+1]));
		}
		printf("%d\n",ans);
	}
}