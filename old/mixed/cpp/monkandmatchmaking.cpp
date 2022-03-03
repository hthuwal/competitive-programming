#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	string s,a,b;
	int q,l,m,n,o;
	cin>>s;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d %d",&l,&m,&n,&o);
		if(s.compare(l-1,m-l+1,s,n-1,o-n+1)==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
}