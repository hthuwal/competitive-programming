#include<stdio.h>
int main()
{
    int t,i,n,m,c,l,ans;
    scanf("%d",&t);
    while(t--)
    {
        int hc[150]={0},jp[150]={0};
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&c,&l);
            hc[l]+=c;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&c,&l);
            jp[l]+=c;
        }
        if(n>=m)
            c=n;
        else
            c=m;
        for(i=0,ans=0;i<110;i++)
        {
            if(jp[i]>hc[i])
                ans+=jp[i]-hc[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
