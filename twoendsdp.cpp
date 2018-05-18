#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
struct score{
	int p1;
	int p2;
};

score scoreboard[2][1100][1100];

// int turn(int p)
// {
// 	return (p==1?2:1);
// }
void evaluate(int a[],int n)
{
	score zero;
	zero.p1=0;
	zero.p2=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scoreboard[0][i][j]=zero;
			scoreboard[1][i][j]=zero;
		}
	}
	for(int i=0;i<n;i++)
	{
		scoreboard[0][i][i].p1=a[i];
		scoreboard[0][i][i].p2=0;

		scoreboard[1][i][i].p1=0;
		scoreboard[1][i][i].p2=a[i];
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=i+1;j<n;j++)
		{
			/**first player plays this turn**/
			score c1 = scoreboard[1][i+1][j];
			score c2 = scoreboard[1][i][j-1];
			c1.p1+=a[i];
			c2.p1+=a[j];
			if(c1.p1>=c2.p1)
				scoreboard[0][i][j]=c1;
			else
				scoreboard[0][i][j]=c2;
			
			/**second player plays this turn**/
			if(a[i]>=a[j])//if tie remove left end -_- to be assumed for correct ans
			{
				c1=scoreboard[0][i+1][j];
				c1.p2+=a[i];
			}
			else
			{
				c1=scoreboard[0][i][j-1];
				c1.p2+=a[j];

			}
			scoreboard[1][i][j]=c1;
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
    int t,a[1100],n,count=0;
    score final;
    while(1)
    {
    	count++;
	    cin>>n;
	    if(n==0)
	    	break;
	    for(int i=0;i<n;i++)
	    {
	    	cin>>a[i];
	    }
	    evaluate(a,n);
	    final = scoreboard[0][0][n-1];
	    n = final.p1-final.p2;
	    cout<<"In game "<<count<<", the greedy strategy might lose by as many as "<<n<<" points.\n";
    }
    
}