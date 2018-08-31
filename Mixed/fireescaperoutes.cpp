#include<cstring>
#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
vector<int> list[200000];
bool isVisited[200000];
long long int count=0;

void dfs(int x){
    isVisited[x]=true;
    count++;
    for(int j=0;j<list[x].size();j++){
        if(!isVisited[list[x][j]]){
            dfs(list[x][j]);
        }
    }
}

int main(){

    int t,n,i,m,a,b;
    cin>>t;
    while(t--){

        cin>>n>>m;
        memset(isVisited,0,n);
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
        int ans=0;
        long long num = 1;

        for(i=0;i<n;i++){
            if(!isVisited[i]){
                ans++;
                count=0;
                dfs(i);
                num*=count;
                num=num%mod;
            }
        }
        cout<<ans<<" "<<num<<endl;
    }
}
