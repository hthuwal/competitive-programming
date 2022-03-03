/*
https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Checks if it is possible to create a subset with sum = t
 * from the elements of the array b of size n. Replaces the number used
 * to acheive the sum with -1.
 * 
 * @param  b [array of elements]
 * @param  n [size fo the array]
 * @param  t [target sum to be achieved]
 * @return true if possible false otherwise
 */
bool is_sum_possible(int b[], int n, int t)
{
    bool dp[n+2][t+2];
    memset(dp, false, sizeof(dp));

    // ios : indices of subset that has appropriate sum if possible
    vector<int> ios[n+2][t+2]; 

    for(int i=0;i<=t;i++)
        dp[0][i] = false;

    for(int i=0;i<=n;i++)
        dp[i][0] = true;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            // Try to take (i-1)th element
            if(b[i-1] <= j and dp[i-1][j-b[i-1]])
            {
                dp[i][j] = true;
                ios[i][j] = ios[i-1][j-b[i-1]];
                ios[i][j].push_back(i-1);
            }
            // Try to do it without (i-1)th element
            else if(dp[i-1][j])
            {
                dp[i][j] = dp[i-1][j];
                ios[i][j] = ios[i-1][j];
            }
            // Can't be done
            else
            {
                dp[i][j] = false;
            }
        }
    }

    if(dp[n][t])
    {
        // replace all used elements by -1
        for(int i=0;i<ios[n][t].size();i++)
            b[ios[n][t][i]] = -1;
    }
    return dp[n][t];
}

/**
 * Check if the array a[] could be divided into K non-empty subsets such 
 * that the sum of elements in every subset is same.
 * @param  a [array]
 * @param  n [size of array]
 * @param  k [number of subsets]
 * @return true if it is possible to divide false otherwise
 */
bool isKPartitionPossible(int a[], int n, int k)
{
    int total_sum = 0;
    for(int i=0;i<n;i++)
        total_sum += a[i];

    // if total sum is not divisible by k then its not possible
    if(total_sum % k != 0)
        return false;
    else
    {
        // sum of eachs subset should be = target
        int target = total_sum / k; 

        // extract k subsets
        while(k>0)
        {
            // if subset whose sum = target is not possible
            if(!is_sum_possible(a, n, target))
                return false;   
            
            // remove all used elements
            int j = 0;
            for(int i=0;i<n;i++)
            {
                if(a[i] != -1)
                    a[j++] = a[i];
            }
            n = j;
            
            k-=1; // one less subset to extract
        }
        return true;
    }
}

int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        int total_sum = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            total_sum += a[i];
        }

        cin>>k;
        cout<<isKPartitionPossible(a, n, k)<<endl;
    }
}