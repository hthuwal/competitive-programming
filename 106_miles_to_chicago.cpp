#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <cfloat>
using namespace std;
#define N 110
vector<int> list[N];
vector<double> cost[N];
void init(){
    for(int i=0;i<N;i++)
    {
        list[i].clear();
        cost[i].clear();
    }
}
void addedge(int a,int b,double c)
{
    list[a].push_back(b);
    cost[a].push_back(c);
    list[b].push_back(a);
    cost[b].push_back(c);
}
void print(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d: ",i+1);
        for(int j=0;j<list[i].size();j++)
            printf("%d %lf | ",list[i][j]+1,cost[i][j]);
        printf("\n");
    }
}
double dijsktra(int source,int n)
{
    set<pair<double,int> > heap;
    vector<double> dist(n,-1);
    heap.insert(make_pair(1,source));
    dist[source]=1;
    while(!heap.empty())
    {
        pair<double,int> cur = *(--heap.end());
        heap.erase(--heap.end());
        int u = cur.second;
        // printf("hc:%d",u);
        for(int i=0;i<list[u].size();i++)
        {
            int v = list[u][i];
            double c = cost[u][i];

            if(dist[u]*c > dist[v])
            {
                if(dist[v]!=-1)
                    heap.erase(heap.find(make_pair(dist[v],v)));
                dist[v]=dist[u]*c;
                heap.insert(make_pair(dist[v],v));

            }
            
        }
    }
    return dist[n-1]*100.0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int a,b,n,m;
    double p;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&m);
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %lf",&a,&b,&p);
            addedge(--a,--b,p/100.0);
        }
        // print(n);
        printf("%0.6lf percent\n",dijsktra(0,n));
    }
}