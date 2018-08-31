#include<cstring>
#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
vector<int> list[200000];
bool isVisited[200000];
int banana[200000];

long long int dfs(int x){
    isVisited[x]=true;
    long long int ans = banana[x];
    for(int j=0;j<list[x].size();j++){
        if(!isVisited[list[x][j]]){
            ans+=dfs(list[x][j]);
        }
    }
    return ans;
}

int main(){

    long long int t,n,i,m,a,b,ans;
    cin>>t;
    vector<long long int>hc;
    while(t--){

        cin>>n>>m;
        memset(isVisited,0,n);
        memset(banana,0,n);
        hc.clear();
        for(i=0;i<n;i++){
            list[i].clear();
        }
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--;
            b--;
            list[a].push_back(b);
            list[b].push_back(a);
        }
        for(i=0;i<n;i++){
            cin>>banana[i];
        }
        for(i=0;i<n;i++){
            if(!isVisited[i]){
               ans=dfs(i);
               hc.push_back(ans);
            }
        }
        ans=hc[0];
        for(i=1;i<hc.size();i++){
            if(hc[i]>ans)
                ans=hc[i];
        }
        cout<<ans<<endl;
    }
}
