#include<cstdio>
int main()
{
    int t,n,m,temp,d,i,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&d);
        for(i=0,count=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp%d==0)
                count+=(temp/d)-1;
            else
                count+=(temp/d);
        }
        if(count>=m)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
