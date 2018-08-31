#include<stdio.h>
#include<string.h>

int main()
{
    char hc[1000000],slag;
    int n,i,flag,count=0;
    scanf("%d",&n);
    scanf("%c",slag);
    while(n--)
    {
        int jp[10]={0};
        gets(hc);
        for(i=strlen(hc)-1,flag=1;hc[i]!=' ';i--)
        {
            if(hc[i]=='0'||hc[i]=='1'||hc[i]=='2'||hc[i]=='4'||hc[i]=='6'||hc[i]=='7'||hc[i]=='9')
            {
                flag=0;
                break;
            }
            else
            {
                jp[hc[i]-'0']++;
            }
        }
        if(flag==1)
        {
            if(jp[8]>=jp[5]&&jp[5]>=jp[3])
            {
                count++;
            }
        }
    }
return 0;
}


