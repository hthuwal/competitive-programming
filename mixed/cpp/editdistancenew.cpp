#include <iostream>
#include <cstdio>
using  namespace std;
int dp[2100][2100];

int min(int a,int b)
{
	return a<b?a:b;
}
int editdistance(string a,string b)
{
	int n=a.length();
	int m=b.length();

	/*just deletion*/
	for(int i=0;i<=n;i++)
		dp[i][0]=i;
	/*just insertion*/
	for(int j=0;j<=m;j++)
		dp[0][j]=j;

	/**top down**/
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			/*replacement*/
			/*if (i-1)th of a and (j-1)th of b 
			same then no need to replace 0
			else replace 1*/
			int d1 = (a[i-1]==b[j-1]?0:1)+dp[i-1][j-1];

			/*insertion*/
			/*insert a character to match the (j-1)th character of b
			  now problem is to covert the (i-1) length part of */
			int d2 = dp[i][j-1]+1;

			/*deletion*/
			/*delete i-1 th character. problem reduces convert i-1 
			length of a to j length of b*/
			int d3 = dp[i-1][j]+1;

			dp[i][j]=min(d1,min(d2,d3));
		}

	return dp[n][m];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	string p,q;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>p>>q;
		cout<<editdistance(p,q)<<"\n";
	}
}
