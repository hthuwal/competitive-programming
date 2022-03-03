#include<iostream>
using namespace std;
int main(){
	int a[1100000],t,n,i,ans,A,B;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<1100000;i++){
			a[i]=0;
		}
		for(i=0,ans=0;i<n;i++){
			cin>>A>>B;
			if(A!=B){
				a[A]++;
				if(a[B]>0)
					a[B]--;
				else if(a[B]==0)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
}