#include<iostream>
using namespace std;
long long int cost=0;
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

		max_heapify(a,largest,n);
	}
}

void build_maxheap(int a[],int n){

	for(int i=n/2 ; i>=1 ; i--){
		max_heapify(a,i,n);
	}

}

void decrement(int a[],int n,int m){
	while(m>0){
	cost+=a[1];
	a[1]--;
	max_heapify(a,1,n);
	m--;
	}
}

int main(){

int a[1000006],n,m,i;
cin>>n>>m;
for(i=1;i<=n;i++)
cin>>a[i];
build_maxheap(a,n);
decrement(a,n,m);
cout<<cost;
}