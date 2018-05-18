#include <cstdio>
#include <vector>
using namespace std;
typedef struct hc{
    int v;
    int w;
} hc;
typedef struct triplet{
    int a,b,c;
} triplet;
class Graph{
private: 
    int v;
    vector<hc> *list;
public:
    Graph(int v)
    {
        this->v=v;
        list = new vector<hc> [v];
    }
    void addedge(int a,int b,int w)
    {
        hc t;
        t.v=b;
        t.w=w;
        list[a].push_back(t);
    }
    void bfs(int source)
    {
        triplet q[v*v+2];
        int f=0,r=0;
        triplet t;
        t.a=source;
        t.b=-1;t.c=-1;
        q[r++]=t;
        while(f<r)
        {
            triplet front  = q[f++];
            printf("%d %d %d\n",front.a,front.b,front.c);
            for(int i=0;i<list[front.a].size();i++)
            {
                hc x = list[front.a][i];
                if(front.b==-1)
                {
                    t.a = x.v;
                    t.b = x.w;
                    t.c = -1;
                    q[r++]=t;
                }
                else if(front.c==-1)
                {
                    t.a = x.v;
                    t.b = front.b;
                    t.c = x.w;
                    q[r++]=t;
                }
                else if(x.w==front.b || x.w==front.c)
                {
                    t=front;
                    t.a=x.v;
                    q[r++]=t;
                }
            }
        }
    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<list[i].size();j++)
            {
                printf("%d ",list[i][j].v);
            }
            printf("\n");
        }
    }
};
int main()
{
    int t;
    for(scanf("%d",&t);t--;)
    {a        scanf("%d %d",&n,&k);
        Graph g(k);
        for(int i=0;i<n;i++)
        {
            a
        }
    }
}