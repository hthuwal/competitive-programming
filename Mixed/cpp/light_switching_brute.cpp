#include <cstdio>
#define N 111111
int a[N];
void init(int n)
{
    for(int i=0;i<n+5;i++)
        a[i]=0;
}
void update(int i,int j)
{
    for(int k=i;k<=j;k++)
        a[k]=1-a[k];
}
int getones(int i,int j)
{
    int count=0;
    for(int k=i;k<=j;k++)
        if(a[k]==1)
            count++;
    return count;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,m,a,b,c;
    scanf("%d %d",&n,&m);
    init(n);
    // print(n);
    while(m--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==0)
            update(b,c);
        else
            printf("%d\n",getones(b,c));
        // print(n);
    }
}