#include <cstdio>
#include <climits>
int recursive(int a[],int n,int start,int pmax)
{
    if(start==n)
        return 1;
    else
    {
        // printf("%d ",start);
        int ans=-1;
        int max=INT_MIN;
        for(int i=start;i<n;i++)
        {
            if(a[i]>max)
                max=a[i];
            if(max>pmax)
                break;
            int t = recursive(a,n,i+1,max);
            if(t!=-1)
            {
                if(ans==-1)
                    ans=0;
                ans+=t;
            }
        }
        // printf("%d ",ans);
        return ans;
    }
}
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