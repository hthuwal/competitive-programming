#include<iostream>
using namespace std;
int main(){
	int t,b;
	cin>>t;
	while(t--){
		cin>>b;
		if(b%2!=0)
			b--;
		b=b/2;
		b=b*(b-1);
		cout<<b/2<<endl;
	}
}