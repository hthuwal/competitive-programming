#include<iostream>
using namespace std;
int main()
{
	int t,n,i,temp;
	cin>>t;
	while(t--){
		int hash[1000000]={0};
		cin>>n;
		for(i=0;i<n;i++){
			cin>>temp;
			hash[temp]=1;
		}
		for(i=0,temp=0;i<1000000;i++){
			if(hash[i])
				temp++;
		}
		cout<<temp<<endl;
	}
}
