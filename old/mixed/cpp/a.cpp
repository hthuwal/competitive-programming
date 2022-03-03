#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T,n;
	cin>>T;
	f(t,1,T+1)
	{
		cout<<"Case #"<<t<<": ";
		cin>>n;
		int count=0;
		int max=0;
		string ans;
		cin.ignore();
		f(i,0,n)
		{
			char s[100];
			cin.getline(s,100);
			count=0;
			int hash[26]={0};
			for(int i=0;i<strlen(s);i++)
			{
				if(s[i]!=' ')
				{
					if(hash[s[i]-'A']==0)
					{
						hash[s[i]-'A']=1;
						count++;
					}
				}
			}
			if(count>max)
			{
				max=count;
				ans = string(s);
			}
			else if(count==max)
			{
				string temp = string(s);
				if(temp<ans)
					ans=temp;
			}
		}
		cout<<ans<<"\n";
	}
}