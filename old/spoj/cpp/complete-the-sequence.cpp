// https://www.wikiwand.com/en/Difference_engine#/Method_of_differences

#include <bits/stdc++.h>

using namespace std;

int table[105][105];

int main()
{
	int t, c, s;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&s,&c);
		for(int i=0;i<s;i++)
			scanf("%d", &table[i][0]);

		for(int col=1;col<s;col++)
			for(int ro=0; ro<s-col; ro++)
				table[ro][col] = table[ro+1][col-1] - table[ro][col-1];


		for(int i=1; i<=c; i++)
		{
			table[0+i][s-1]=table[0+i-1][s-1];
			for(int j=1; j<s; j++)
			{
				table[j+i][s-1-j] = table[j+i-1][s-1-j] + table[j+i-1][s-j];
			}
		}
	
		// for(int ro=0; ro<s+c;ro++)
		// {
		// 	for(int col=0; col<s+c-ro; col++)
		// 		printf("%4d ", table[ro][col]);
		// 	printf("\n");
		// }
		for(int i=0;i<c;i++)
			printf("%d ",table[s+i][0]);
		printf("\n");
	}
}