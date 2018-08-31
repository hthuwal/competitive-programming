#include<stdio.h>
#include<stdlib.h>
int r,f;
void push(char x)
{
    if((r==max && f==1)||f==r+1)
    {
        printf("Overflow");
        return;
    }
    if(r==-1)
    {
        r=0;
        f=0;
        q[r]=x;
        return;
    }
    else if(r==max)
    {
        r=0;
        q[r]=x;
        return;
    }
    r++;
    q[r]=x;
}
