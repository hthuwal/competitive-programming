#include <cstdio>
int main()
{
    int t,m,x,y;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&m);
        x=m/3;
        y=2*(m/3);
        if(m%3==1)
            x++;
        else if(m%3==2)
        {
            x++;y++;
        }
        printf("%d %d\n",x,y);
    }
}