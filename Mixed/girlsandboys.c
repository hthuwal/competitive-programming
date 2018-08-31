#include<stdio.h>
int main()
{
    int g,b,n,x,i;
    while(1)
    {
        scanf("%d %d",&g,&b);
        if(g==-1&&b==-1)
            break;
        else if(g>=b)
        {
            n=b;
            x=g;
        }
        else
        {
            n=g;
            x=b;
        }
        for(i=0;i<n-1;i++)
        {
            if((x/2)>=(x-x/2))
                x=x/2;
            else
                x=x-x/2;
        }
        printf("%d\n",x);
    }
    return 0;
}
