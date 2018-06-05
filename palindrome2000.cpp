#include<bits/stdc++.h>
using namespace std;
char str[5001];
int memo[5001][5001];

int recursive(int l, int h)
{
	if(l>h) return INT_MAX;
	if(l==h) return 0; // single character already palindrome
	if(memo[l][h] == -1)
	{	
		if(l == h-1) 
			memo[l][h] = (str[l] == str[h]) ? 0: 1; // if aa then 0 if ab then 1 -> aba
		else if(str[l] == str[h]) 
			memo[l][h] = recursive(l+1, h-1);
		else 
			memo[l][h] = min(recursive(l, h-1), recursive(l+1, h)) + 1;
	}
	return memo[l][h];
}

int main()
{	
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			memo[i][j]=-1;
	printf("%d", recursive(0, n-1));
}