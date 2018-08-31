/**check whether the graph is a bipartite graph or not**/
/**do normal bfs assigning alternate colors to neighbours if you encounter a neighbour with same color than graph is not bipartite**/

#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
vector <int> list[3000];

int flag;
int isVisited[3000];

void bfs(int x){
    queue <int> s;
    isVisited[x]=1;
    s.push(x);
    while(!s.empty()){
        int top=s.front();
        s.pop();
        for(int j=0;j<list[top].size();j++){

            if(isVisited[list[top][j]]==isVisited[top]){
                flag=1;
            }
            else if(isVisited[list[top][j]]==-1){
                s.push(list[top][j]);
                isVisited[list[top][j]]=(!isVisited[top]);
            }
        }
    }

}
int main(){

    int t,n,i,a,b,m;
    cin>>t;
    for(int k=1;k<=t;k++){

        cin>>n>>m;
        for(i=0;i<n;i++){
            list[i].clear();
        }
        memset(isVisited,-1,n*sizeof(int));

        flag=0;

        for(i=0;i<m;i++){
            cin>>a>>b;
            a--;
            b--;
            list[a].push_back(b);
            list[b].push_back(a);
        }

        /**bfs**/
        for(i=0;i<n;i++){
            if(flag==1)
                break;
            if(isVisited[i]==-1){
                isVisited[i]=1;
                bfs(i);
            }
        }
        cout<<"Scenario #"<<k<<":"<<endl;
        if(flag==1){
            cout<<"Suspicious bugs found!"<<endl;
        }
        else
        {
            cout<<"No suspicious bugs found!"<<endl;
        }
    }
}
