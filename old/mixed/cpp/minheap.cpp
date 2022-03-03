#include<iostream>
using namespace std;

/***  bottom up Min heaping Functions ***/
	/* Utility Function to maintain the min heap property */
		void min_heapify(int a[],int i,int n){
			
			int left = 2*i; // left child 
			int right = 2*i+1; // right child
			int temp,smallest;
			if(left<=n && a[left] < a[i])
				smallest = left;
			else
				smallest = i;

			if(right <=n && a[right] < a[smallest])
				smallest = right;

			if(smallest!=i){

				temp = a[i];
				a[i] = a[smallest];
				a[smallest] = temp;

				min_heapify(a,smallest,n); // cause we dont know after swapping smallest would remain a max heap or not
			}
		}
	/* End of Utility Function */

	/**Arr[ N/2+1 ] to Arr[ N ] are leaf nodes,and each node is a 1 element heap. We can use min_heapify function 
	in a bottom up manner on remaining nodes, so that we can cover each node of tree.**/

		void build_minheap(int a[],int n){

			for(int i=n/2 ; i>=1 ; i--){
				min_heapify(a,i,n);
			}

		}
/** End of Max Heaping Functions **/

int main(){
	int a[]={0,4,5,1,6,7,3,2};
	build_minheap(a,7);
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
}