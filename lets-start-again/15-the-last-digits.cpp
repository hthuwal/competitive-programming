// https://www.spoj.com/problems/LASTDIG/

#include<bits/stdc++.h>
#define lli long long int
using namespace std;

map<int, vector<int> > dict;

bool find(vector<int> temp, int n){for(int t: temp) if(t==n) return true;return false;}

void preprocess()
{
	for(int i=0;i<10;i++)
	{
		int j = i % 10;
		while(!find(dict[i], j))
		{
			dict[i].push_back(j);
			j = (j*i) % 10;
		}
	}
}

int main()
{
	preprocess();
	cin.sync_with_stdio(false);
	lli t, a, b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(b==0)
		{
			cout<<1<<"\n";
			continue;
		}

		a = a % 10;
		lli poss = dict[a].size();
		lli index = -1 + b % poss;
		if(index == -1)
			index = poss - 1;
		cout<<dict[a][index]<<"\n";
	}
}