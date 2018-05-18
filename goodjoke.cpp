#include<iostream>
using namespace std;
int main()
{
	int t,i,j,n,a,b;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a>>b;
		}
		a=1;
		for(i=2;i<=n;i++){
			a=a^i;
		}
		cout<<a<<endl;
	}
}

