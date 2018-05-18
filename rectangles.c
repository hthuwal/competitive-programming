#include<stdio.h>
int main()
{
    int n,i,ans;
    scanf("%d",&n);
    for(i=2,ans=n;i<=sqrt(n);i++)
    {
        ans=ans+(n/i)-i+1;
    }
    printf("%d\n",ans);
    return 0;
}
