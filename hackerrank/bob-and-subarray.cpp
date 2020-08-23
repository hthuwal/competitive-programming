/*
Bob has an array A having n integers. Bob wants to determine the addition of Bitwise OR of all the subarrays present in the array. 
Note : Subarray of an array is a contiguous block of elements containing any number of elements from the array.
Note : Bitwise OR of a subarray containing a single element will be the element itself .
Compute the sum of the Bitwise  of all the subarrays present in the array.
 */


#include<bits/stdc++.h>
#define lli long long int
#define vi vector<lli>
using namespace std;

/*
Returns number of subarrays of array of length k
 */
lli number_of_subarrays(lli k)
{
	return (k*(k+1))/2;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int max_set_bit = -1; // highest bit set amongst the numbers
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		if(int(log2(a[i])) > max_set_bit)
			max_set_bit = int(log2(a[i]));
	}

	lli total_subarrays = number_of_subarrays(n);

	lli ans = 0; //final answer

	for(int bit_number=max_set_bit; bit_number>=0 ;bit_number--)
	{
		// temp[i] will store the value (bit_number)th bit of a[i]
		int temp[n]; 

		// in case of 1 bit numbers, sum of ORs of all subarrays
		// is equal to the number of subarrays if all the numbers are 1
		lli ans_i = total_subarrays;

		for(int i=0;i<n;i++) 
			temp[i] = (a[i] & (1<<bit_number))>>bit_number;

		for(int i=0;i<n;i++)
		{
			if(temp[i]==0)  // how many continuous numbers are zeroes
			{
				int length = 1;
				while(++i < n && temp[i] == 0)
					length += 1;

				// the sub arrays consisting only of these elements 
				// will have zero sum. => not part of answer
				ans_i -= number_of_subarrays(length);
			}
		}

		// since the ans_i is the sum if these were the 0th bits
		// but these are (bit_number)th bit
		// so multiply by 2**(bit_number)
		ans += int(pow(2, bit_number))*ans_i;
	}
	printf("%lld\n", ans);
}