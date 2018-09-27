/*
Given a range[, ] and a value  we need to add  to all the numbers whose indices are in the range from [a, b].

We can do in O(1) update by adding k to index a and add -k to index b+.

Doing this kind of update, the  ith number in the array will be prefix sum of array from index 1 to i 
because we are adding k to the value at index a and subtracting k from the value at index b+1
 and taking prefix sum will give us the actual value for each index after  operations .

So, we can do all  updates in O(m) time. Now we have to check the largest number in the original array. 
i.e. the index i such that prefix sum attains the maximum value.

We can calculate all prefix sums as well as maximum prefix sum in O(n) time which will execute in time.
*/

#include <bits/stdc++.h>
#define lli long
int main()
{
	int n,m,l,h,v;
	scanf("%d %d",&n,&m);
	lli arr[n+1]={0};
	for(int i=0; i<m;i++)
	{
		scanf("%d %d %d",&l,&h,&v);
		arr[--l] += v;
		arr[h] -= v;
	}

	lli ans = arr[0];
	for(int i=1;i<n;i++)
	{
		arr[i] += arr[i-1];
		if(arr[i]>ans)
			ans = arr[i];
	}
	printf("%lld\n",ans);
}