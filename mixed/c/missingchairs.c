#include<stdio.h>
# define jp 1000000007
long long int hc(long long int x,long long int y)
{
        if(y==1)
            return x%jp;
        if(y==2)
            return ((x%jp)*(x%jp))%jp;
        else if(y%2==0)
            return (hc(hc(x,y/2),2))%jp;
        else
            return ((x%jp)*(hc(hc(x,(y-1)/2),2))%jp)%jp;
}
int main()
{
    int t;
    long long int n,ans,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=hc(2,n);
        ans=(ans-1)%jp;
        printf("%lld\n",ans);
    }
    return 0;
}
