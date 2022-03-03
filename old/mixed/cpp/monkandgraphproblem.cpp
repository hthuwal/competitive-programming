#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#define vi vector<int>

using namespace std;
class Graph{
private:
    int v;
    vi *list;
public:
    Graph(int v)
    {
        this->v = v;
        list = new vi[v];
    }
    void addedge(int a,int b)
    {
        list[a].push_back(b);
        list[b].push_back(a);
    }
    int dfs(int source,vector<bool> &visited)
    {
        stack<int> st;
        st.push(source);
        int count = 0;
        while(!st.empty())
        {
            int top = st.top(); st.pop();
            if(!visited[top])
            {
                visited[top]=true;
                count+=list[top].size();
                for(int i=0;i<list[top].size();i++)
                {
                    if(!visited[list[top][i]])
                        st.push(list[top][i]);
                }
            }
        }
        // cout<<count<<" "<<(count/2)<<endl;
        return count/2;
    }
    int ans()
    {
        vector<bool> visited(v,false);
        int max = 0;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                int current = dfs(i,visited);
                if(current>max)
                    max=current;
            }
        }
        return max;
    }
};
int main()
{
    freopen("in.txt","r",stdin);
    int n,m,a,b;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g.addedge(--a,--b);
    }
    cout<<g.ans()<<endl;
}