/*** a[i]a[j]>a[i]+a[j] for i<j is false if
1. any of the a[i] or a[j] is 1 or 0
2. both of them equals to "2"**/
#include<iostream>
using namespace std;

int main(){
    long long int t,n,j,i,ans;
    long long int a[110000]={0};
    long long int hc[110000]={0};
    long long int two[110000]={0};
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a[0];
        hc[0]=0;
        two[0]=0;
        for(i=1;i<n;i++){
            cin>>a[i];
            if(a[i-1]==0 || a[i-1]==1){
                hc[i]=hc[i-1]+1;
            }
            else
            {
                hc[i]=hc[i-1];
            }
            if(a[i-1]==2)
            {
                two[i]=two[i-1]+1;
            }
            else
            {
                two[i]=two[i-1];
            }
        }
        for(i=n-1,ans=0;i>=0;i--)
        {
            if(a[i]==2){
                ans+=(i-two[i]-hc[i]);
            }
            else if(a[i]!=1 && a[i]!=0){
                ans+=(i-hc[i]);
            }
        }
        cout<<ans<<endl;
    }
}
