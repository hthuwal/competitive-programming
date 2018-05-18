#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	string a,b,ans;
	int p[26];
	int q[26],i,j,n;
	while(cin>>a>>b)
	{
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		ans="";
		for(i=0;i<a.length();i++)
		{
			p[a[i]-'a']++;
		}
		for(i=0;i<b.length();i++)
		{
			q[b[i]-'a']++;
		}
	
		for(i=0;i<26;i++)
		{
			if(p[i]!=0 && q[i]!=0)
			{
				n = (p[i]<q[i]?p[i]:q[i]);
				for(j=0;j<n;j++)
				{
					ans+=char('a'+i);
				}
			}
		}
		sort(ans.begin(),ans.end());	
		cout<<ans<<endl;
	}
}