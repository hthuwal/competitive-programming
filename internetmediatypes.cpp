#include<iostream>
using namespace std;
struct list{
	string a;
	string b;
};
int main(){
	int n,q,i,j,k;
	bool flag = false;
	string jp,am;
	cin>>n>>q;
	list hc[n];
	for(i=0;i<n;i++){
		cin>>hc[i].a>>hc[i].b;
	}
	for(i=0;i<q;i++){
		flag=false;
		cin>>jp;
		j=jp.length()-1;
		for(;j>=0;j--){
			if(jp[j]=='.')
			{
				am=jp.substr(j+1,jp.length()-j-1);
				for(k=0;k<n;k++){
					if(hc[k].a == am){
						flag=true;
						cout<<hc[k].b<<endl;
						break;
					}
				}
				break;
			}
		}
		if(flag==false)
			cout<<"unknown"<<endl;
	}
}