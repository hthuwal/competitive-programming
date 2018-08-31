#include <bits/stdc++.h>

using namespace std;
string dp[10][10][10][10][101];
string original;
int turns;

void init()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)	
			for(int k=0;k<10;k++)
				for(int l=0;l<10;l++)
					for(int m=0;m<101;m++)
						dp[i][j][k][l][m] = "-1";
}

string incr(string n, int i)
{
	if(n[i]=='9')
		n[i]='0';
	else
		n[i]=n[i]+1;

	return n;
}

string ans(string n, int t)
{
	string &result = dp[n[0]-'0'][n[1]-'0'][n[2]-'0'][n[3]-'0'][t];
	
	if(result != "-1")
		return result;
	
	if(t > turns)
	{
		return n;
	}
	else
	{
		string cand[] = {ans(incr(n,0), t+1), ans(incr(n,1), t+1), ans(incr(n,2), t+1), ans(incr(n,3), t+1)};
		if(t%2 == 0)
		{
			result = *(min_element(cand, cand+4));
		}
		else
		{
			result = *(max_element(cand, cand+4));
		}
		return result;
	}
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		init();
		cin>>original>>turns;
		if(ans(original, 1) > original)
			printf("Ada\n");
		else
			printf("Vinit\n");
	}
}