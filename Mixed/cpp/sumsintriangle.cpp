#include<iostream>
using namespace std;
int main(){
int t,i,j,n,hc[110][110];
cin>>t;
while(t--){
cin>>n;for(i=0;i<n;i++)for(j=0;j<=i;j++)cin>>hc[i][j];for(i=n-2;i>=0;i--)for(j=0;j<=i;j++)hc[i][j]+=max(hc[i+1][j],hc[i+1][j+1]);cout<<hc[0][0]<<endl;}
}
