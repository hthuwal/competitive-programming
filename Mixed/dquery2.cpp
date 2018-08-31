#include <iostream>
#include <cstdio>
#include <set>
#define MAX 31000
#define sint set<int>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    int u,n,x,q,y;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(scanf("%d",&q);q--;)
    {
        scanf("%d %d",&x,&y);

        u=sint(a+x,a+y+1).size();
        printf("%d\n",u);
    }
}