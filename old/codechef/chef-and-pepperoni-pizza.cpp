/**
 * https://www.codechef.com/COOK109B/problems/PEPPERON
 */

#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int n,t;
char pizza[1010][1010];
int left_halfs[1010];
int right_halfs[1010];

int left_pizza;
int right_pizza;

void preprocess()
{
	left_pizza = 0;
	right_pizza = 0;

	for(int i=0;i<n;i++)
	{
		left_halfs[i] = 0; //left half of row
		right_halfs[i] = 0; // right half of row

		for(int j=0;j<n;j++)
		{
			if(j<n/2)
				left_halfs[i] += pizza[i][j] - '0';
			else
				right_halfs[i] += pizza[i][j] - '0';
		}

		left_pizza += left_halfs[i];
		right_pizza += right_halfs[i];
	}
}

int solve()
{
	int ans = abs(left_pizza - right_pizza);

	for(int i=0;i<n;i++)
	{
		ans = min(
			ans, 
			abs(left_pizza - 2 * left_halfs[i] + 2 * right_halfs[i] - right_pizza)
		);
	}
	return ans;
}

int main()
{
	cin.sync_with_stdio(false);
	cin>>t;

	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>pizza[i];

		preprocess();

		cout<<solve()<<"\n";
	}
}