#include <iostream>
using namespace std;

int main()
{
	int t,n,hc[10],temp,ans,i;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<10;i++){
			hc[i]=0;
		}
		for(i=0;i<n;i++){
			cin>>temp;
			hc[temp%10]++;
		}
		for(i=0,ans=0;i<10;i++){
			if(hc[i]!=0){
				ans+=(hc[i]-1);
			}
		}
		cout<<ans<<endl;
	}
}
