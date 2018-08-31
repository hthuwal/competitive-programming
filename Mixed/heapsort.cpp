#include<iostream>
using namespace std;

/***  bottom up Max heaping Functions ***/
	/* Utility Function to maintain the max heap property */
		void max_heapify(int a[],int i,int n){
			
			int left = 2*i; // left child 
			int right = 2*i+1; // right child
			int temp,largest;
			if(left<=n && a[left] > a[i])
				largest = left;
			else
				largest = i;

			if(right <=n && a[right] >a[largest])
				largest = right;

			if(largest!=i){

				temp = a[i];
				a[i] = a[largest];
				a[largest] = temp;

				max_heapify(a,largest,n); // cause we dont know after swapping largest would remain a max heap or not
			}
		}
	/* End of Utility Function */

	/**Arr[ N/2+1 ] to Arr[ N ] are leaf nodes,and each node is a 1 element heap. We can use max_heapify function 
	in a bottom up manner on remaining nodes, so that we can cover each node of tree.**/
		void build_maxheap(int a[],int n){

			for(int i=n/2 ; i>=1 ; i--){
				max_heapify(a,i,n);
			}

		}
/** End of Max Heaping Functions **/


/******************************************************************************************************************/
/*1) Heap Sort:

We can use heaps in sorting the elements in a specific order in efficient time.
Let’s say we want to sort elements of array Arr in ascending order. We can use max heap to perform this operation.

Idea: We build the max heap of elements stored in Arr, and the maximum element of Arr will always be at the root of the heap.

Leveraging this idea we can sort an array in the following manner.

Processing:

1) Initially we will build a max heap of elements in Arr.

2) Now the root element that is Arr[ 1 ] contains maximum element of Arr. After that, we will exchange this element with the 
last element of Arr and will again build a max heap excluding the last element which is already in its correct position and 
will decrease the length of heap by one.

3) We will repeat the step 2, until we get all the elements in their correct position.

4) We will get a sorted array.*/
/******************************************************************************************************************/

/** Heap Sort **/
	void heapsort(int a[],int n){
		build_maxheap(a,n);
		int temp;
		for(int i = n;i>=2;i--){
			/*swapping the root with the last node that is first element of array with last unswapped element*/
				temp = a[1];
				a[1] = a[i];
				a[i] = temp;
			/*swapping complete*/
			max_heapify(a,1,i-1); //or alternatively we can use build_maxheap(a,i-1);
		}
	}
/** End of Heap Sort **/

int main(){
	int a[]={0,4,3,7,1,8,5};
	heapsort(a,6);
	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	}
}