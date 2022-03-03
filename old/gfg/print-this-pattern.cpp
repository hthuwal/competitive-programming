/*
https://practice.geeksforgeeks.org/problems/print-this-pattern/0
*/

// Why is pattern printing cumbersome

#include<bits/stdc++.h>
using namespace std;

void print(int i, int n)
{
	for(int j=0;j<n;j++)
		printf("%d", i);
}

int main()
 {
	int t,n;
	for(scanf("%d", &t); t--;)
	{
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			int j,count = 0;
			for(j=n;j>=n-i;j--)
			{
				count++;
				print(j, 1);
			}
			j++;
			print(j, 2*(n-count));
			for(j=j+1;j<=n;j++)
			{
				print(j,1);
			}
			printf("\n");
		}
		for(int i=n-2;i>=0;i--)
		{
			int j,count = 0;
			for(j=n;j>=n-i;j--)
			{
				count++;
				print(j, 1);
			}
			j++;
			print(j, 2*(n-count));
			for(j=j+1;j<=n;j++)
			{
				print(j,1);
			}
			printf("\n");
		}

	}
	return 0;
}