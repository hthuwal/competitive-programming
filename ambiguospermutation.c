#include<stdio.h>
int main()
{
    int a[100006],i,flag,n,t;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1,flag=1;i<=n;i++)
        {
            if(a[a[i]]==i)
                continue;
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
    }
    return 0;
}
