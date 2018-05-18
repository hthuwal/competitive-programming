#include <cstdio>
#define N 1049999
int matinarr[N];
int bit[N];
void init(int n)
{
    for(int i=0;i<=(n*(n+1));i++)
    {    
        bit[i]=0;
        matinarr[i]=0;
    }
}
void update_bit(int num,int n,int x,int y=-1)
{
    int i;
    if(y==-1)
        i=x;
    else
        i = x*n+y+1;
    // printf("i:%d\n",i);
    int old = matinarr[i];
    matinarr[i]=num;
    for(;i<=(n*n);i+=(i&-i))
    {
        bit[i]+=(num-old);
    }
}
int getsum_arr(int x)
{
    int sum=0;
    for(;x>0;x-=(x&-x))
        sum+=bit[x];
    return sum;
}
int getsum(int x1,int y1,int x2,int y2,int n)
{
    int sum=0;
    for(int i=x1;i<=x2;i++)
    {
        sum += (getsum_arr(i*n+y2+1)-getsum_arr(i*n+y1-1+1));
    }
    return sum;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n,x,y,num,p,q;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        init(n);
        char in[5];
        while(1)
        {
            scanf("%s",in);
            // printf("%s\n",in);
            if(in[1]=='E')
            {
                scanf("%d %d %d",&x,&y,&num);
                // printf("%d %d %d\n",x,y,num);
                update_bit(num,n,x,y);
            }
            else if(in[1]=='U')
            {
                scanf("%d %d %d %d",&x,&y,&p,&q);
                printf("%d\n",getsum(x,y,p,q,n));
            }
            else
                break;
        }
        printf("\n");
    }
}