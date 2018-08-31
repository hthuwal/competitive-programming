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

int main(){
	int a[]={0,1,4,3,7,8,9,10};
	build_maxheap(a,7);
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
}