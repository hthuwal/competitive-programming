/**
 * Maximum Sum of all subarrays of size k
 *
 * GFG: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d",&n, &k);
	    
	    // Sltore the indices of the integer
	    deque<int> dq; 
        
	    // Reading Input
        vector<int> arr(n, 0);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);

		        
        for(int i=0; i<n; i++)
        {
        	// print only once window completes
        	if(i>=k)
        		printf("%d ", arr[dq.front()]);

        	// delete all numbers from the front
        	// that are out of window
        	while(!dq.empty() and dq.front() <= i - k)
        		dq.pop_front();

        	// delete all numbers from the back 
        	// smaller than the current numbers
        	while(!dq.empty() and arr[i] >= arr[dq.back()])
        		dq.pop_back();

        	dq.push_back(i);
        }

        printf("%d\n", arr[dq.front()]);
    }
	return 0;
}