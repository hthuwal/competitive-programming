// A Dequeue (Double ended queue) based method for printing maixmum element of
// all subarrays of size k (slidng window)
#include<iostream>
#include<deque>
using namespace std;

void printmax(int a[],int k,int n)
{
	// Create a Double Ended Queue, hc that will store indexes of array elements
    // The queue will store indexes of useful elements in every window and it will
    // maintain decreasing order of values from front to rear in hc, i.e., 
    // a[hc.front[]] to a[hc.rear()] are sorted in decreasing order

	deque<int> hc;

	int i;
	/* Process first k (or first window) elements of array */
	for(i=0;i<k;i++)
	{
		// For very element, the previous smaller elements are useless so
        // remove them from Qi
		while((!hc.empty()) && a[i]>=a[hc.back()])
			hc.pop_back();

		// Add new element at rear of queue
		hc.push_back(i);
	}

	// Process rest of the elements, i.e., from a[k] to a[n-1]
	for(;i<n;i++)
	{
		// The element at the front of the queue is the largest element of
        // previous window, so print it
		cout<<a[hc.front()]<<" ";

		// Remove the elements which are out of this window
		while((!hc.empty()) && hc.front()<=i-k)
			hc.pop_front();

		// Remove all elements smaller than the currently
        // being added element (remove useless elements)
		while((!hc.empty()) && a[i]>=a[hc.back()])
			hc.pop_back();
		// Add current element at the rear of Qi
		hc.push_back(i);
	}
	// Print the maximum element of last window
	cout<<a[hc.front()];
}
int main()
{
	int n,k,a[1100000];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>k;
	printmax(a,k,n);
}