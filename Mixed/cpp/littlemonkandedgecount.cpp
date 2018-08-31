#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#define vi vector<int>
using namespace std;

class Graph
{
private:
    int v;
    vi *list;
public:
    Graph(int v)
    {
        this->v=v;
        list = new vi[v];
    }
    void addedge(int a,int b)
    {
        list[a].push_back(b);
        list[b].push_back(a);
    }
    int dfs(int s,vector<bool> &visited)
    {
        stack<int> st;
        st.push(s);
        int count=0;
        while(!st.empty())
        {
            int top = st.top(); st.pop();
            if(!visited[top])
            {
                count++;
                visited[top]=true;
                for(int i=0;i<list[top].size();i++)
                {
                    if(!visited[list[top][i]])
                    {
                        st.push(list[top][i]);
                    }
                }
            }
        }
        return count;
    }
    int ans(pair<int,int> s)
    {
        vector<bool> visited(v,false);
        visited[s.first]=true;
        int p = dfs(s.second,visited);
        visited[s.first]=false;
        visited[s.second]=true;
        int q = (v-p);
        if(p==0)
            return q;
        else if(q==0)
            return p;
        return p*q;
    }
};

int main()
{
    freopen("in.txt","r",stdin);
    int n,q,a,b;
    cin>>n>>q;
    Graph g(n);
    vector<pair<int,int> > hc;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        g.addedge(--a,--b);
        hc.push_back(make_pair(a,b));
    }
    for(int i=0;i<q;i++)
    {
        cin>>a;
        cout<<g.ans(hc[--a])<<endl;
    }
    
}