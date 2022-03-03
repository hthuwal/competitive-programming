/*This problem is just a derivative of Matrix Chain Multiplication problem. In the original problem, the objective was to minimize the total number of multiplications. 
Here the objective would be to maximize the length of the segment to be sold. 
Let's say we store DP[i][j] as the maximum length we can sell from the chunk S[i,j].
base cases:
DP[i][i]=0 if S[i,i]= 0 
DP[i][i]= 1 if S[i,i]= 1
Main Memoization:
if in S[i,j]  One[i,j] > Zero[i,j] then DP[i][j]=j-i+1
 else DP[i][j]=max(DP[i][k]+DP[k+1][j]) where  i <= k < j.
 
Final ans stored in DP[0][n-1] (considering 0-based index and n= length of string)
*/

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int length[210][210];// length[i][j] denotes maximum length possible for string i to j

int hc(string a)
{
	int n = a.length();
	
	int ones[n+1];// to store sum upto ith index 1=>1 and 0=>-1 therefore if sum<=0 implies 0 more else 1 more
	ones[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]=='0')
			ones[i]=ones[i-1];
		else
			ones[i]=ones[i-1]+1;
	}

	for(int i=1;i<=n;i++)
	{
		if(a[i-1]=='1')
		{
			length[i][i]=1;
		}
		else
		{
			length[i][i]=0;
		}
	}
	for(int i=2;i<=n;i++)// i denotes length of string
	{
		for(int j=1;j<=n-i+1;j++)//j denotes starting of  every contiguous string of i length in given string
		{
			int k=j+i-1;//ending of every contiguous string of i length in given string

			/* if number of 1's in j to k is more than 0 then 
			lenght[j][k]=k-j+1; that is this entire string is valid and can be sold
			*/
			int noofones = ones[k]-ones[j-1];

			if(noofones > i-noofones)
				length[j][k]=i;

			/* else trying to break this i length string 
			with starting index j and ending index k
			at every l between them */
			else{
				int max = 0;
				for(int l=j;l<=k-1;l++)
				{
					int d2=length[j][l]+length[l+1][k];

					if(d2>max)
					{
						max=d2;
						
					}
				}
				length[j][k]=max;
			}
		}
	}
	return length[1][n];
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cin>>s;
		cout<<hc(s)<<"\n";
	}
}