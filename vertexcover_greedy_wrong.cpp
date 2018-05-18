#include <cstdio>
#include <set>
#include <vector>

using namespace std;
vector<int> list[111111];
vector<int> degree(111111,0);
set<pair<int,int> > hc_heap;
int main()
{
    freopen("in.txt","r",stdin);
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&a,&b);
        list[a-1].push_back(b-1);
        list[b-1].push_back(a-1);
        degree[a-1]++;
        degree[b-1]++;
    }

    for(int i=1;i<=n;i++)
        hc_heap.insert(make_pair(degree[i],i));

    int e = n-1;
    int ans = 0;
    while (e>0 && !hc_heap.empty())
    {
        pair<int,int> maxd = *(--hc_heap.end());
        hc_heap.erase(--hc_heap.end());
        ans++;
        e-=(maxd.first);
        // printf("%d ",maxd.second);
        degree[maxd.second] = 0;

        for(int i=0;i<list[maxd.second].size();i++)
        {
            int nbr = list[maxd.second][i];
            if(degree[nbr]>0 && hc_heap.find(make_pair(degree[nbr],nbr)) != hc_heap.end())
            {
                hc_heap.erase(hc_heap.find(make_pair(degree[nbr],nbr)));
                degree[nbr]--;
                hc_heap.insert(make_pair(degree[nbr],nbr));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}