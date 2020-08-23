#include<stdio.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int hc[1500],t,i,j,k,n,m,flag,ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&m);
        for(j=0;j<m;j++)
        {
            scanf("%d",&hc[j]);

        }
        qsort(hc,m,sizeof(int),cmpfunc);
        for(k=0,ans=0,flag=0;k<m;k++)
        {
            ans+=hc[m-1-k];
            if(ans>=n)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("Scenario #%d:\n%d\n\n",i,k+1);
        }
        else
        {
            printf("Scenario #%d:\nimpossible\n\n",i);
        }
    }
    return 0;
}
