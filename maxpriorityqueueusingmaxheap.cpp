#include<iostream>
using namespace std;
int n;
/***  bottom up Max heaping Functions ***/
	/* Utility Function to maintain the max heap property */
		void max_heapify(int a[],int i){
			
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

				max_heapify(a,largest); // cause we dont know after swapping largest would remain a max heap or not
			}
		}
	/* End of Utility Function */

	/**Arr[ N/2+1 ] to Arr[ N ] are leaf nodes,and each node is a 1 element heap. We can use max_heapify function 
	in a bottom up manner on remaining nodes, so that we can cover each node of tree.**/
		void build_maxheap(int a[]){

			for(int i=n/2 ; i>=1 ; i--){
				max_heapify(a,i);
			}

		}
/** End of Max Heaping Functions **/

/*Extract Maximum: In this operation, the maximum element will be returned and the last element of heap will
 be placed at index 1 and max_heapify will be performed on node 1 as placing last element on index 1 will 
 violate the property of max-heap.
**/
int extract_maximum (int a[ ])
{
    if(n == 0)
    {
cout<< “Can’t remove element as queue is empty”;
        return -1;
    }
    int max = a[1];
    a[1] = a[n];
    n = n -1;
    max_heapify(a, 1);
    return max;
}

/**Increase Value: In case increasing value of any node, may violate the property of max-heap, so we will 
swap the parent’s value with the node’s value until we get a larger value on parent node.**/

void increase_value (int a[ ], int i, int val)
{
    if(val < a[ i ])
    {
        cout<<”New value is less than current value, can’t be inserted” <<endl;
        return;
    }
    a[ i ] = val;
    while( i > 1 and a[ i/2 ] < a[ i ])
    {
        int temp = a[i/2];
        a[i/2]=a[i];
        a[i]=temp;
        i = i/2;
    }
}

Insert Value :

void insert_value (int a[ ], int val)
{
    n = n + 1;
    a[ n ] = -1;  //assuming all the numbers greater than 0 are to be inserted in queue.
    increase_val (a, n, val);
}