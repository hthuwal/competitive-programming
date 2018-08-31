#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int main(){
    int a[11000],b[11000];
    int t,i,n,m,hash[11000];
    stack<int>ans;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(hash,0,11000);
        memset(a,0,m);
        memset(b,0,m);
        for(i=0;i<m;i++){
            cin>>a[i]>>b[i];
        }
        for(i=m-1;i>=0;i--){
            if(hash[a[i]]==0 && hash[b[i]]==0){
                hash[a[i]]=1;
                hash[b[i]]=1;
                ans.push(i);
            }
        }
        while(!ans.empty()){

            cout<<ans.top()<<" ";
            ans.pop();
        }
        cout<<endl;
    }
}
