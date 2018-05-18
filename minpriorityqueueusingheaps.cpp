/**not valid for similar value**/
#include<iostream>

using namespace std;
int size;

void min_heapify(int a[],int i,int n){
	int left = 2*i;
	int right =2*i+1;
	int smallest;
	if(left<=n && a[left] < a[i])
		smallest=left;
	else
		smallest=i;
	if(right<=n && a[right] < a[smallest])
		smallest =right;

	if(smallest!=i){
		int temp = a[smallest];
		a[smallest]=a[i];
		a[i]=temp;
		min_heapify(a,smallest,n);
	}
}

void build_minheap(int a[],int n){
	for(int i=n/2;i>=1;i--){
		min_heapify(a,i,n);
	}
}

void insert(int a[],int x,int n){
	n++;
	size++;
	a[n]=x;
	while(n/2 >= 1 && a[n/2] > a[n]){
		int temp = a[n/2];
		a[n/2]=a[n];
		a[n]=temp;
		n=n/2;
	}
}

void front(int a[],int n){
	cout<<endl<<"The front is "<<a[1]<<endl;
}

void pop(int a[],int n){
	if(n!=0)
	{
	cout<<endl<<a[1]<<" is popped out."<<endl;
	a[1]=a[n];
	size--;
	n--;
	min_heapify(a,1,n);
	}
	else
	{
		cout<<"\nQueue Empty\n";
	}
}
int main()
{
	int p,x,a[1000];
	size = 0;
	while(1)
	{
		cout<<"Enter Your Choic\n"<<"1.Insert\n"<<"2.Front\n"<<"3.Pop\n"<<"4.Exit\n"<<endl;
		cin>>p;
		switch(p){
			case 1:cin>>x;
				   insert(a,x,size);
				   break;

			case 2:front(a,size);
				   break;
			case 3:pop(a,size);
				   break;
			case 4:return 0;
				   break;
		}
	}
}
