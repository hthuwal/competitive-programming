#include <iostream>
#include <cstdio>
using namespace std;
struct triplet{
    int first;
    int second;
    int third;
};
triplet blocks[200];
int mymax(int a,int b)
{
    return a>b?a:b;
}
int dp(int n,int m)
{
    int table[n+5][n+5];
    for(int i=0;i<=n;i++)
    {
        table[0][i]=0;
        table[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            table[i][j]=0;
            for(int k=0;k<m;k++)
            {
                if(blocks[k].first < i && blocks[k].second <j)
                {
                    table[i][j]=mymax(table[i][j],table[blocks[k].first][blocks[k].second]+blocks[k].third);
                } 
            }
        }
    }
    return table[n][n];
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         printf("%d ",table[i][j]);
    //     }
    //     printf("\n");
    // }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    while(1)
    {
        scanf("%d",&m);
        if(m==0)
            break;
        int a,b,c;
        n=0;
        for(int i=0;i<6*m;i+=6)
        {
            scanf("%d %d %d",&a,&b,&c);
            blocks[i].first=a;      blocks[i].second=b;     blocks[i].third=c;
            blocks[i+1].first=b;    blocks[i+1].second=a;   blocks[i+1].third=c;
            blocks[i+2].first=a;    blocks[i+2].second=c;   blocks[i+2].third=b;
            blocks[i+3].first=c;    blocks[i+3].second=a;   blocks[i+3].third=b;
            blocks[i+4].first=b;    blocks[i+4].second=c;   blocks[i+4].third=a;
            blocks[i+5].first=c;    blocks[i+5].second=b;   blocks[i+5].third=a;
            n = mymax(mymax(n,a),mymax(b,c));
        }
        // printf("%d\n",n);
        printf("%d\n",dp(n+1,6*m));
        
    }
}
