/********************************************************************************************
There is a greedy algorithm for finding minimum vertex cover of a tree which uses DFS traversal.

For each leaf of the tree, select its parent (i.e. its parent is in minimum vertex cover).
For each internal node:
if any of its children is not selected, then select this node.

Proof of correctness

11
down vote
We first observe the following: There is an optimal cover CC, and no leaf is in CC. This is true since in any optimal cover XX you can replace all leaves in XX with their parents, and you get a vertex cover which is not larger than XX.

Now take any optimal cover CC that does not contain leaves. Since no leave is selected, all parents of the leaves have to be in CC. In other words, CC coincides with the greedy cover on the leaves and their parents. Next, we take out all edges that have been covered already. We can now apply the same argument again: In the remaining tree, no leaf needs to be selected, but then their parents have to be selected. And this is exactly what the greedy algorithm does. (A vertex becomes a leaf iff all of its children are selected in the previous step.) We repeat this argument we determined a complete vertex cover.
*********************************************************************************************/
#include <cstdio>
#include <set>
#include <vector>

using namespace std;
vector<int> list[111111];

set<pair<int,int> > hc_heap;
int count=0;

int dfs(int s, int parent)
{
    if(list[s].size()==1 && list[s][0]==parent)
        return 1;

    bool is_parent_of_leaf = false;
    bool is_future_parent = false;

    for(int i=0;i<list[s].size();i++)
    {
        if(list[s][i]!=parent)
        {
            int x = dfs(list[s][i], s);
            if( x == 1)
                is_parent_of_leaf = true;
            else if( x == -1)
                is_future_parent = true;
        }
    }
    if(is_parent_of_leaf || is_future_parent)
    {
        count++;
        return 0;
    }
    return -1;
}

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
    }
    dfs(0,-1);
    printf("%d\n",count);
}