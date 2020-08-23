#include <cstdio>
int gcd(int a,int b)
{
    while(b!=0)
    {
        int t = a%b;
        a=b;
        b=t;
    }
    return a;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,a,b,c;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        printf("Case %d: ",i);
        if(c%gcd(a,b)==0)
            printf("Yes\n");
        else 
            printf("No\n");
    }
}