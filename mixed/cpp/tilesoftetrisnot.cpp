#include <cstdio>

int main()
{
   freopen("in.txt","r",stdin);
    long long int x,y;
    while(1)
    {
        scanf("%lld %lld",&x,&y);
        if(x==0 && y==0)
            break;
        if(x%y==0)
            printf("%lld\n",x/y);
        else if(y%x==0)
            printf("%lld\n",y/x);
        else
        printf("%lld\n",x*y);
    }
}