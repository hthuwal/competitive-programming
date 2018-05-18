#include<stdio.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int t,n,i,ans;
    scanf("%d",&t);
    while(t--)
    {
        int a[1100]={0},b[1100]={0};
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        qsort(a,n,sizeof(int),cmpfunc);
        qsort(b,n,sizeof(int),cmpfunc);
        for(i=0,ans=0;i<n;i++)
        {
            ans+=a[i]*b[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
