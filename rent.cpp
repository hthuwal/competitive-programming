/** weighted job scheduling **/
/**
The Greedy Strategy for activity selection doesn’t work here as a 
schedule with more jobs may have smaller profit or value.
1) First sort jobs according to finish time.
2) Now apply following recursive process. 
   // Here arr[] is array of n jobs
   findMaximumProfit(arr[], n)
   {
     a) if (n == 1) return arr[0];
     b) Return the maximum of following two profits.
         (i) Maximum profit by excluding current job, i.e., 
             findMaximumProfit(arr, n-1)
         (ii) Maximum profit by including the current job            
   }

How to find the profit including current job?
The idea is to find the latest job before the current job (in 
sorted array) that doesn't conflict with current job 'arr[n-1]'. 
Once we find such a job, we recur for all jobs till that job and
add profit of current job to result.
In the above example, "job 1" is the latest non-conflicting
for "job 4" and "job 2" is the latest non-conflicting for "job 3".
*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define N 11111
#define lli long long int
struct job{
	lli s,f,c;
};
job arr[N];
lli dp[N+5];
bool compare(job a,job b)
{
	return a.f<b.f;
}

lli find_prev_possible(lli x)
{
	for(lli i=x-1;i>=0;i--)
	{
		if(arr[i].f < arr[x].s)
			return i;
	}
	return -1;
}
lli dynamic(lli n)
{
	dp[0]=arr[0].c;
	for(lli i=1;i<n;i++)
	{
		lli profit_including = arr[i].c;
		lli j = find_prev_possible(i);
		if(j!=-1)
			profit_including += dp[j];
		dp[i]=(profit_including>dp[i-1]?profit_including:dp[i-1]);
	}
	return dp[n-1];
}
int main()
{
	freopen("in.txt","r",stdin);
	lli t,n;
	for(scanf("%lld",&t);t--;)
	{
		scanf("%lld",&n);
		for(lli i=0;i<n;i++)
		{
			scanf("%lld %lld %lld",&arr[i].s,&arr[i].f,&arr[i].c);
			arr[i].f+=arr[i].s;
		}
		sort(arr,arr+n,compare);
		// for(lli i=0;i<n;i++)
		// 	printf("%lld %lld %lld\n",arr[i].s,arr[i].f,arr[i].c);
		printf("%lld\n",dynamic(n));
		
		// for(lli i=0;i<n;i++)
		// 	printf("%lld ",dp[i]);
	}
}