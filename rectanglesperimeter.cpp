/**
 *  for an ith rectangle you have 2 choices, either use it as it is or rotate it. If p(i,0) is the max perimeter with ith rectangle in the original position and p(i,1) denote the max perimeter if ith rectangle rotated then this yields a simple recurrence:

p(i,0)=max(p(i-1,0)+width(i)+|height(i)-height(i-1)|,p(i-1,1)+width(i)+|height(i)-width(i-1)|)

and

p(i,1)=max(p(i-1,0)+height(i)+|width(i)-height(i-1)|,p(i-1,1)+height(i)+|width(i)-width(i-1)|)

The final answer would be max(p(n-1,0),p(n-1,1))

with base cases p(0,0)=height(i) and p(0,1) = width(i);

Explanation: Considering current ,i.e. ith rectangle the (i-1)th rectangle could have been placed normally or rotated. Taking the max of perimeters from both choices does the trick.
 */
#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	return (a>b?a:b);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	int height[n];
	int width[n];

	for(int i=0;i<n;i++)
	{
		cin>>width[i]>>height[i];
	}
	
	int dp[2][n];//first row denotes placed on first edge
			//second rown denotes placed on second edge

	dp[0][0]=width[0];
	dp[1][0]=height[0];

	for(int i=1;i<n;i++)
	{
		dp[0][i]=max(dp[0][i-1]+width[i]+abs(height[i]-height[i-1]),
			         dp[1][i-1]+width[i]+abs(height[i]-width[i-1]));

		dp[1][i]=max(dp[0][i-1]+height[i]+abs(width[i]-height[i-1]),
					 dp[1][i-1]+height[i]+abs(width[i]-width[i-1]));
	}
	cout<<max(dp[0][n-1],dp[1][n-1]);
}