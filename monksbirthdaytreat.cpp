include<cstring>
#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
vector<int> list[200000];
vector<int> list2[200000];

int main(){

    int t,n,i,m,a,b,ans,flag,j;
        cin>>n>>m;
        memset(isDependent,0,n);
        for(i=0;i<n;i++){
            list[i].clear();
        }

        for(i=0;i<m;i++){
            cin>>a>>b;
            a--;
            b--;
            list[b].push_back(a);
            list2[a].push_back(b);
        }
        ans=n;
        for(i=0;i<n;i++){
            if(!list[i].empty()){
                    if(list)
            }
        }
        if(ans==0)
            ans=1;
        cout<<ans<<endl;
}
