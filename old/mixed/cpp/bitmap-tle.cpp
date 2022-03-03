#include<cstdio>
#include<iostream>
#include<list>
#include<cmath>
using namespace std;
struct mylove
{
    int x;
    int y;
};
int main()
{
    int t,i,j,n,m,jh[185][185],min1,temp;
    char c;
    list<mylove> jyoti ;
    mylove jp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%c",&c);
            for(j=1;j<=m;j++)
            {
                scanf("%c",&c);
                if(c=='1')
                {
                    jp.x=i;
                    jp.y=j;
                    jyoti.push_back(jp);
                }
            }
        }
        list<mylove>::iterator k;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                for(k=jyoti.begin(),min1=200;k!=jyoti.end();k++)
                {
                    temp=abs(i-(k->x))+abs(j-(k->y));
                    if(temp<min1)
                        min1=temp;
                    jh[i][j]=min1;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                printf("%d ",jh[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
