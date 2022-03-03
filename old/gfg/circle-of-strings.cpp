#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define lli long long int

int nsb(int n)
{
	int count= 0;
	while(n>0)
	{
		n=(n&(n-1));
		count++;
	}
	return count;
}

int bit(int i, int n)
{
	return (n>>i) & 1;
}

class Graph{
public:
	int v;
	vector<vi> adj;
	Graph(int num_nodes)
	{
		v = num_nodes;
		adj = vector<vi>(num_nodes, vi(num_nodes, false));
	}
	void add_edge(int a, int b)
	{
		adj[a][b]=true;
	}
	bool is_hamiltonian_cycle()
	{
		lli subset = 1<<v;
		bool dp[subset][v];
		for(lli sub=0; sub<subset; sub++)
		{
			for(int j=0; j<v; j++)
			{
				dp[sub][j] = false;
				if(not bit(0, sub))
					dp[sub][j] = false;
				else if(nsb(sub) == 1 and bit(j, sub))
					dp[sub][j] = true;
				else if(bit(j, sub))
				{
					for(int nbr=0;nbr<v;nbr++)
					{
						if(nbr != j and adj[nbr][j] and bit(nbr, sub))
							dp[sub][j] = (dp[sub ^ (1<<j)][nbr] or dp[sub][j]);
					}
				}
			}
		}
		// for(int i=0;i<subset;i++)
		// {
		// 	for(int j=0;j<v;j++)
		// 	{
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		for(int i=1;i<v;i++)
		{
			if(dp[subset-1][i] and adj[i][0])
				return true;
		}
		return false;
	}
};
int main()
{
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		unordered_map<string, int> hc;
		vector<string> strs(n, "");
		for(int i=0;i<n;i++)
		{
			cin>>strs[i];
			hc[strs[i]]=i;
		}

		Graph g(n);
		for(int i=0;i<strs.size();i++)
		{
			for(int j=0;j<strs.size();j++)
			{
				if(j != i)
				{
					int l = strs[i].length();
					if(strs[i][l-1] == strs[j][0])
						g.add_edge(hc[strs[i]], hc[strs[j]]);
				}
			}
		}
		// for(auto each: g.adj)
		// {
		// 	for(int i=0;i<each.size();i++)
		// 	{
		// 		cout<<each[i]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// 
		if(n == 1)
		{
			int l = strs[0].length();
			if(strs[0][l-1] == strs[0][0])
				cout<<true;
			else
				cout<<false;
		}
		else
			cout<<g.is_hamiltonian_cycle()<<endl;
	}
}