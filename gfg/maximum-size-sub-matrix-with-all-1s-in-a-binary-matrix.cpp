/**
 * maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix  
 *
 * My solution O(n^2 log(n))
 *
 * An O(n^2) algo exists here
 * https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/ 
 */

#include<bits/stdc++.h>
#define fs(i,s,n) for(int i=s;i<n;i++)
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
int arr[55][55];
int dp[55][55];

/**
 * Prefix Sum. dp[i][j] denotes the sum of elements in the rectangle upto [i][j] fom 0,0;
 * @param n number of rows.
 * @param m number of columns.
 */
void preprocess(int n, int m)
{
    dp[0][0] = arr[0][0];
    
    fs(i,1,m) dp[0][i] = dp[0][i-1] + arr[0][i];
    fs(i,1,n) dp[i][0] = dp[i-1][0] + arr[i][0];
    
    fs(i,1, n)
        fs(j,1,m)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];

}

/**
 * Returns the sum of the rectangle with
 * @param  si top-left-x
 * @param  sj top-left-y
 * @param  ei bottom-right-x
 * @param  ej bottom-right-y
 * @return The sum of the rectangle witth (si, sj) and (ei, ej) as the opposite ends
 */
int get_sum(int si, int sj, int ei, int ej)
{
    int ans = 0;
    ans += dp[ei][ej];
    if(si == 0 and sj == 0)
        return ans;
    else if(si == 0)
        ans -= dp[ei][sj-1];
    else if(sj == 0)
        ans -= dp[si-1][ej];
    else
        ans = ans - dp[ei][sj-1] - dp[si-1][ej] + dp[si-1][sj-1];
    return ans;
}

/**
 * Check if a subsquare of size k exists in n,m s.t sum of elements
 * is equal to k*k
 */
int ispossible(int k, int n, int m)
{
    f(i,n)
        f(j,m)
            if(i+k-1<n and j+k-1<m and get_sum(i, j, i+k-1, j+k-1) == k*k)
                return true;

    return false;
}

/*
 * Binary search over possible values of k
 */
int findk(int n, int m)
{
    int l = 1;
    int h = min(n, m);
    while(l<=h)
    {
        int mid = l+((h-l)>>1);
        if(ispossible(mid, n, m))
            l = mid+1;
        else
            h = mid-1;
    }
    return l-1;
}
int main()
{
	int t, n, m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n, &m);
        f(i,n) f(j, m) scanf("%d", &arr[i][j]);

        preprocess(n, m);
        printf("%d\n", findk(n, m));
    }
	return 0;
}