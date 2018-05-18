#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char hc[150];
    int i,flag;
    while(scanf("%s",hc)!=EOF)
    {
        if(hc[0]>=97&&hc[0]<=122&&hc[strlen(hc)-1]!='_')
        {
            for(i=0,flag=-1;hc[i]!='\0';i++)
            {
                if((hc[i]=='_'&&flag==1)||(hc[i]=='_'&&(hc[i-1]=='_'||hc[i+1]==' ')))
                {
                    flag=-2;
                    printf("Error!\n");
                    break;
                }
                else if(hc[i]=='_')
                {
                    flag=0;
                }
                else if(hc[i]>=65&&hc[i]<=90)
                {
                    if(flag==0)
                    {
                        flag=-2;
                        printf("Error!\n");
                        break;
                    }
                    else
                        flag=1;
                }
            }
            if(flag==0)
            {
                for(i=0;hc[i]!='\0';i++)
                {
                    if(hc[i]=='_')
                    {
                        printf("%c",(hc[i+1]-'a'+'A'));
                        i++;
                    }
                    else
                        printf("%c",hc[i]);
                }
                printf("\n");
            }
            else if(flag==1)
            {
                for(i=0;hc[i]!='\0';i++)
                {
                if(hc[i]>=65&&hc[i]<=90)
                {
                    printf("_%c",(hc[i]-'A'+'a'));
                }
                else
                    printf("%c",hc[i]);
                }
                printf("\n");
            }
            else if(flag==-1)
            {
                printf("%s\n",hc);
            }
        }
        else
        {
            printf("Error!\n");
        }
    }
    return 0;
}
