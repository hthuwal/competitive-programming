#include<iostream>
using namespace std;


void max_heapify(long long int a[],long long int i,long long int n){
	long long int left = 2*i; // left child 
	long long int right = 2*i+1; // right child
	long long int temp,largest;
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
void build_maxheap(long long int a[],long long int n){

	for(long long int i=n/2 ; i>=1 ; i--){
		max_heapify(a,i,n);
	}
}
void swap(long long int *a,long long int *b){
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	long long int a[110000],i,n,ans;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		ans=1;
		if(i<=2)
			cout<<"-1"<<endl;
		else{
			build_maxheap(a,i);
			ans*=a[1];
			swap(a[1],a[i]);
			max_heapify(a,1,i-1);
			ans*=a[1];
			swap(a[1],a[i-1]);
			max_heapify(a,1,i-2);
			ans*=a[1];
			cout<<ans<<endl;
		}
	}
}