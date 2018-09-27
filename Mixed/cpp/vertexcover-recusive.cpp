/*****************************************************************************************************************************
The idea is to consider following two possibilities for root and recursively for all nodes down the root.
1) Root is part of vertex cover: In this case root covers all children edges. We recursively calculate size of vertex covers for left and right subtrees and add 1 to the result (for root).

2) Root is not part of vertex cover: In this case, both children of root must be included in vertex cover to cover all root to children edges. We recursively calculate size of vertex covers of all grandchildren and number of children to the result (for two children of root).

http://www.geeksforgeeks.org/vertex-cover-problem-set-2-dynamic-programming-solution-tree/

without memoization (1000 nodes)
real    0m0.033s
user    0m0.024s
sys     0m0.000s

with memoization (1000 nodes)
real    0m0.013s
user    0m0.008s
sys     0m0.000s
******************************************************************************************************************************/
#include <cstdio>
#include <set>
#include <vector>

using namespace std;
vector<int> list[111111];
vector<int> memoi(111111,0);
int count=0;

int recursive(int root, int parent)
{
    if(list[root].size()==1 && list[root][0]==parent)
        return 0;

    if(memoi[root]!=0)
        return memoi[root];

    int root_is_taken = 1;
    for(int i =0;i<list[root].size();i++)
    {
        if(list[root][i]!=parent)
        {
            root_is_taken += recursive(list[root][i], root);
        }
    }

    int root_not_taken = 0;

    for(int i =0;i<list[root].size();i++)
    {
        int nbr = list[root][i];
        if(nbr!=parent)
        {
            root_not_taken += 1;
            for(int j=0;j<list[nbr].size();j++)
            {
                if(list[nbr][j]!=root)
                    root_not_taken += recursive(list[nbr][j], nbr);
            }            
        }
    }

    memoi[root]=(root_is_taken < root_not_taken ? root_is_taken : root_not_taken);
    return memoi[root];
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
    
    printf("%d\n",recursive(0,-1));
}