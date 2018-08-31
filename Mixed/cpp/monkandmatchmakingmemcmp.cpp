#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	char a[110000];
	int q,l,m,n,o;
	gets(a);
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d %d",&l,&m,&n,&o);
		if(m-l == o-n){
			
		if(memcmp(&a[l-1],&a[n-1],m-l+1)==0)
			printf("Yes\n");
		else
			printf("No\n");
		}
		else
			printf("NO\n");

	}
}