#include <bits/stdc++.h>
using namespace std;

int hc_hash[26][111111];

int main()
{
	int t,n,q,l,r;
	string str;

	
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		cin>>str;
		for(int j=0;j<26;j++)
			hc_hash[j][0]=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<26;j++)
				hc_hash[j][i+1]=hc_hash[j][i];
			
			int cur = str[i] - 'a';
			hc_hash[cur][i+1] += 1;
		}

		while(q--)
		{
			cin>>l>>r;
			bool wtf = false;
			for(int i=0;i<26;i++)
			{
				for(int j=l+2;j<=r;j++)
				{
					if(hc_hash[i][j] - hc_hash[i][l-1] > (j-l+1)/2)
					{
						wtf = true;
						break;
					}
				}
				if(wtf)
					break;
			}
			if(wtf)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}

		
	}
}