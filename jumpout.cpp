#include <cstdio>
int main()
{
    freopen("in.txt","r",stdin);
    int n,a[11111];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=n+1;
    for(int i=n-1;i>=0;i--)
    {
        // printf("%d ",ans);
        if(a[i]>=n-i && i<ans)
            ans=i+1;
    }
    printf("%d\n",ans);
}