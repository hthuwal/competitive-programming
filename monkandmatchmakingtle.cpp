#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string s,a,b;
	int q,l,m,n,o;
	cin>>s;
	cin>>q;
	while(q--){
		cin>>l>>m>>n>>o;
		a=s.substr(l-1,m-l+1);
		b=s.substr(n-1,o-n+1);
		if(a==b)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}