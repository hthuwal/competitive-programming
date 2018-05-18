#include<stdio.h>
long long int hc(long long int x,long long int y)
{
    if(y==1)
        return x%10;
    else if(y==2)
        return ((x%10)*(x%10))%10;
    else if(y%2==0)
        return (hc(hc(x,y/2),2))%10;
    else if(y%2==1)
        return ((x%10)*(hc(hc(x,(y-1)/2),2)%10))%10;
}
long long int main()
{
    long long int t,a,b;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",hc(a,b));
    }
    return 0;
}
