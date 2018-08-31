#include<iostream>
using namespace std;
int main()
{
	long long int i,n,count;
	while(1){
		cin>>n;
		if(n==0)
			break;
		count=0;
		while(n>1){
			n=n/2;
			count++;
		}
		cout<<count<<endl;
	}
    return 0;
}
