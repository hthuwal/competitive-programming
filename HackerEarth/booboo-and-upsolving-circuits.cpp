/**
 * https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/booboo-and-upsolving-circuits/
 */

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

bool verify(lli arr[], int n, int num_days, lli ans)
{
    int num_tasks = n;
    
    for(int i=0; i<n;)
    {
        lli temp = ans;

        if(arr[i] > temp) // if its not possible to current task return false
            return false;
            
        /* If its possible to do current task, do as many tasks you can do today */
        while(i<n and arr[i]<=temp) 
        {
            temp -= arr[i];
            i++;
            num_tasks--;
        }

        num_days--;
    }
    
    if(num_tasks == 0 and num_days >= 0)
        return true;
    else 
        return false;
}

int main()
{
    int n, m;
    cin>>n>>m;
    lli arr[n];
    lli sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }        

	/*        Binary Search over possible answer space            */
	/* 		  Similar to finding the left most occurrence         */
    
    lli ul = sum;   // You can do all work on single day
    lli ll = 0;     // You can do no work on any day
    while(ll<=ul)
    {
        lli mid = ll + (ul - ll) / 2;  

        /* check if mid a valid solution or not */
        bool is_possible = verify(arr, n, m, mid);
        
        if(is_possible)  // if mid is possible solution then ther might be some smaller solution
            ul = mid-1;  // search in left half
        else
            ll = mid+1;  // if not possible solution then try some bigger solution
    }

    // no need to handle does not occur condition
    // because ther is always a solution
    cout<<ul+1<<endl;
}
