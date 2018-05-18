#include<stdio.h>
int main()
{
    int t,a,b,i,hc,jp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        for(i=0,hc=0;a!=0;i++)
        {
            hc=hc*10+a%10;
            a=a/10;
        }
        for(i=0,jp=0;b!=0;i++)
        {
            jp=jp*10+b%10;
            b=b/10;
        }
        a=hc+jp;
        for(i=0,b=0;a!=0;i++)
        {
            b=b*10+a%10;
            a=a/10;
        }
        printf("%d\n",b);
    }
    return 0;
}
