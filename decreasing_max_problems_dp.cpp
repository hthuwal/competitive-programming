#include <cstdio>
#include <climits>
int greedy
int main()
{
    int t,n;
    freopen("in.txt","r",stdin);
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("%d\n",recursive(a,n,0,INT_MAX));
    }
}