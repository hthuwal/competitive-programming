#include <iostream>
using namespace std;
int gcd(int a, int b){
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}
int main(){
	int t,a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b;
		c=gcd(a,b);
		a=a/c;
		b=b/c;
		cout<<b<<" "<<a<<endl;

	}
}