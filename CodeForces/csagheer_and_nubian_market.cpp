#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define lli long long int

int costs[111111];
int n, s;
map<pii, pii> hc;

void dp()
{
	lli sobc[2][n+1];
	lli soi[2][n+1];

	//initialization
	for(int i=0;i<=n;i++)
	{
		sobc[0][i] = soi[0][i] = 0;
	}
	sobc[1][0] = soi[1][0] = -1;

	int items;
	for(items=1; items<=n;items++)
	{
		for(int index=1;index<=n;index++)
		{
			if(index<items)
			{
				sobc[1][index] = soi[1][index] = -1;
			}
			else
			{
				// I dont try to buy this item
				lli sobc1 = sobc[1][index-1];
				lli soi1 = soi[1][index-1];
				lli cost1 = sobc1 + soi1 * items;

				// I try to buy this item
				lli sobc2 = sobc[0][index-1];
				lli soi2 = soi[0][index-1];
				lli cost2 = sobc2 + costs[index] + (soi2 + index) * items;

				
				if(sobc1 == -1 && sobc2 == -1)
					sobc[1][index] = soi[1][index] = -1;
				else if(sobc1 == -1 && cost2 <= s)
				{
					sobc[1][index] = sobc2 + costs[index];
					soi[1][index] = soi2 + index;
				}
				else if(sobc2 == -1 && cost1 <= s)
				{
					sobc[1][index] = sobc1;
					soi[1][index] = soi1;
				}
				else
				{
					if(cost2 < cost1 && cost2 <= s)
					{
						sobc[1][index] = sobc2 + costs[index];
						soi[1][index] = soi2 + index;
					}
					else if(cost1 <= s)
					{
						sobc[1][index] = sobc1;
						soi[1][index] = soi1;
					}
					else
					{
						sobc[1][index] = soi[1][index] = -1;
					}
				}
			}
		}
		if(sobc[1][n] == -1)
			break;
		for(int i=0;i<=n;i++)
		{
			sobc[0][i] = sobc[1][i];
			soi[0][i] = soi[1][i];
		}

	}
	items--;
	cout<<items<<" "<<(sobc[0][n] + (soi[0][n]*items));
}

pii recursive(int sobc, int soi, int i, int noi)
{	


	int cost = sobc + soi*noi;
	if(i > n || cost == s)
	{
		return make_pair(noi, cost);
	}

	pii key = make_pair(s - cost, i);

	if(hc.find(key) != hc.end())
		return hc[key];
	
	// consider not buying the ith item
	pii ans1 = recursive(sobc, soi, i+1, noi);


	// consider buying the ith item
	int new_sobc = sobc + costs[i];
	int new_soi = soi + i;
	int new_noi = noi + 1;

	int new_cost = new_sobc + new_soi * new_noi;

	if(new_cost <= s) // can buy this
	{
		pii  ans2 = recursive(new_sobc, new_soi, i+1, new_noi);
		if(ans1.first > ans2.first)
			hc[key]=ans1;
		else if(ans2.first > ans1.first)
			hc[key]=ans2;
		else{
			if(ans1.second < ans2.second)
				hc[key]=ans1;
			else
				hc[key]=ans2;
		}
	}
	else
		hc[key]=ans1;
	return hc[key];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>costs[i];
	pii ans = recursive(0, 0, 1, 0);
	cout<<ans.first<<" "<<ans.second<<"\n";
	// print(vi(costs, costs+n), n);
	dp();
}