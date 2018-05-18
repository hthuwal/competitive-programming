#include<stdio.h>
int main()
{
    int a,d,t,i,n,x,y,z;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&x,&y,&z);
        n=(2*z)/(x+y);
        d=(y-x)/(n-5);
        a=x-2*d;
        printf("%d\n",n);
        for(i=0;i<n;i++)
        {
            printf("%d ",a);
            a=a+d;
        }
    }
    return 0;
}
