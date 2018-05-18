#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int x,flag,i,t;
    char a,b,hc[50],jp[50],mylove[50];
    scanf("%d",&t);
    while(t--)
    {
        flag=-1;
        scanf("%s %c %s %c %s",hc,&a,jp,&b,mylove);
        for(i=0;i+6<strlen(hc);i++)
        {
            if(hc[i]=='m')
            {
                flag=0;
                break;
            }
        }
        if(flag!=0)
        {
        for(i=0;i+6<strlen(jp);i++)
        {
            if(jp[i]=='m')
            {
                flag=1;
                break;
            }
        }
        }
        if(flag!=0&&flag!=1)
        {
        for(i=0;i+6<strlen(mylove);i++)
        {
            if(mylove[i]=='m')
            {
                flag=2;
                break;
            }
        }
        }
        if(flag==0)
        {
            x=atoi(mylove)-atoi(jp);
            printf("\n%d + %s = %s",x,jp,mylove);
        }
        else if(flag==1)
        {
            x=atoi(mylove)-atoi(hc);
            printf("\n%s + %d = %s",hc,x,mylove);
        }
        else if(flag==2)
        {
            x=atoi(hc)+atoi(jp);
            printf("\n%s + %s = %d",hc,jp,x);
        }
    }
    return 0;
}
