#include<stdio.h>
int main()
{
    int x,y,z;
    while(1)
    {
    scanf("%d %d %d",&x,&y,&z);
    if(x==0&&y==0&&z==0)
        break;
    else if(y-x==z-y)
    {
        printf("AP %d\n",z+y-x);
    }
    else if(y*y==x*z)
    {
        x=(z*z)/y;
        printf("GP %d\n",x);
    }
    }
    return 0;
}
