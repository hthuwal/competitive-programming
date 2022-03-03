#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int main()
{
	long long int p,q,n,temp;
	queue<long long int> s;
	long long int ans[100005],a[1003];
	memset(ans,-1,sizeof(ans));
	cin>>p>>q;
	cin>>n;
	for(long long int i=0;i<n;i++)
		cin>>a[i];
	ans[p]=0;
	s.push(p);
	while(!s.empty())
	{
		long long int hc = s.front();
		s.pop();
		cin>>temp;
		if(hc==q)
			break;
		for(long long int i=0;i<n;i++)
		{
			long long int jp = a[i];
			jp = (jp*hc)%100000;

			if(ans[jp]==-1)
			{
				ans[jp]=ans[hc]+1;
				s.push(jp);
			}
		}
	}
	cout<<ans[q];
}