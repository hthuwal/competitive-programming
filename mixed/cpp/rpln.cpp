#include <cstdio>
#include <cmath>
#define N 101000
#define LN 17
int arr[N];
int lookup[N][LN];
void preprocess(int n)
{
    for(int i=0;i<n;i++)
        lookup[i][0]=i;

    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;(i+(1<<j)-1)<n;i++)
            if( arr[ lookup[i][j-1] ] <
                arr[ lookup[i+(1<<(j-1))][j-1] ])
                lookup[i][j]=lookup[i][j-1];
            else
                lookup[i][j]=lookup[i+(1<<(j-1))][j-1];
}   
int RMQ(int L,int R)
{
    int j = (int)log2(R-L+1);
    if( arr[ lookup[L][j] ] < arr[ lookup[R-(1<<j)+1][j] ])
        return arr[ lookup[L][j] ];
    else
        return arr[ lookup[R-(1<<j)+1][j] ];
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n,q,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Scenario #%d:\n",i);
        scanf("%d %d",&n,&q);
        for(int j=0;j<n;j++)
            scanf("%d",&arr[j]);
        preprocess(n);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",RMQ(--a,--b));
        }
    }
}