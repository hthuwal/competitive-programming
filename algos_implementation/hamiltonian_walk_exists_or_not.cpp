#include <bits/stdc++.h>

using namespace std;
int adj[20][20];

int ith_bit(int n, int i)
{
	return (n >> i) & 1;
}

int nnzb(int n)
{
	int count = 0;
	for(;n>0;n>>=1)
		if((n & 1))
			count ++;
	return count;
}


class Graph{
int nn; // number of nodes
vector<int> *adj;
public:
	Graph(int v)
	{
		nn = v;
		adj = new vector<int> [v];
	}
	void addedge(int a, int b)
	{
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bool check_if_hamiltonian_path_exists()
	{
		int ns = (int) pow(2, nn); // number of subsets;
		bool dp[ns][nn];
		for(int subset=0; subset<ns;subset++)
		{
			for(int i=0;i<nn;i++)
			{
				dp[subset][i] = false;
				if(nnzb(subset)==1 and ith_bit(subset, i))
					dp[subset][i] = true;
				else if (nnzb(subset) > 1 and ith_bit(subset,i))
				{
					for(int nbr: adj[i])
					{
						if(ith_bit(subset, nbr))
							dp[subset][i] = dp[subset][i] || dp[subset ^ (1<<(i+1))][nbr];

					}
				}
			}
		}

		for(int i=0;i<nn;i++)
			if(dp[ns-1][i] == true)
				return true;
		return false;	
	}
};

int main()
{
	int n, m,a,b;
	cin>>n>>m;
	Graph g(n);
	while(m--)
	{
		cin>>a>>b;
		g.addedge(a, b);
	}
	cout<< (g.check_if_hamiltonian_path_exists()?"YES\n":"NO\n");
}