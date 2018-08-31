#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
using namespace std;
int main()
{
	int i,t,n,k,ans;
	set<int>hc;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		hc.insert(t);
	}
	std::set<int>::iterator p;
	ans=0;
	for(p=hc.begin();p!=hc.end();p++)
	{
		if(hc.count(*p+k))
			ans++;
		if(hc.count(*p-k))
			ans++;
	}
	printf("%d",ans/2);	
}
