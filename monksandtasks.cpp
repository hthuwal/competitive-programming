#include<iostream>
#define x 110000
using namespace std;

// MODIFIED MERGE SORT //
// a is the array according to which the two araay must be sorted that is a is the binary array //
void merge(long long int a[],long long int b[],long long int lower,long long int mid,long long int max){
	
	long long int temp1[x],temp2[x],i,j,k;
	for(i=lower,j=mid+1,k=lower;i<=mid && j<=max;){
		if(a[i]<=a[j])
		{
			temp1[k]=a[i];
			temp2[k]=b[i];
			i++;
			k++;
		}
		else if(a[i]>a[j])
		{
			temp1[k]=a[j];
			temp2[k]=b[j];
			j++;
			k++;
		}
	}

	while(i<=mid){
		temp1[k]=a[i];
		temp2[k]=b[i];
		i++;
		k++;
	}
	while(j<=max){
		temp1[k]=a[j];
		temp2[k]=b[j];
		j++;
		k++;
	}

	for(i=lower;i<=max;i++){
		a[i]=temp1[i];
		b[i]=temp2[i];
	}

}
void mergesort(long long int a[],long long int b[],long long int lower,long int max){
	if(lower<max){
		int mid=(lower+max)/2;
		mergesort(a,b,lower,mid);
		mergesort(a,b,mid+1,max);
		merge(a,b,lower,mid,max);
	}
}

/* END OF MERGE SORT */

/* CALCULATION OF SET BITS THAT IS 1 */

long long int setbitcount( long long int n){
	long long int count=0;
	while(n)
	{
		count += n & 1;
		n=n>>1;
	}
	return count;
}

/* END OF SETBIT CALCULATION */

int main(){

	long long int t,i,n,array[x],binary[x];
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>array[i];
			binary[i]=setbitcount(array[i]);
		}
		mergesort(binary,array,0,n-1);
		for(i=0;i<n;i++){
			cout<<array[i]<<" ";
		}
		cout<<endl;
	}
}