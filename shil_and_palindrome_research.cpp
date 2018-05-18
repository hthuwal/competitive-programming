#include <cstdio>
int bit[26][1111111];
char st[1111111];
void init(int n)
{
    for(int i=0;i<26;i++)
        for(int j=0;j<=n+1;j++)
            bit[i][j]=0;
}
void print(int n)
{
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",bit[i][j]);
        }
        printf("\n");
    }
}
void update_bit(int x,char b,int n,bool cr=false)
{
    int r = st[x-1]-'a';
    int rn = b-'a';
    st[x-1]=b;
    // printf("%d %d\n",r,rn);
    if(!cr)
        for(;x<=n;x+=(x&-x))
        {
            bit[r][x]--;
            bit[rn][x]++;
        }
    else
        for(;x<=n;x+=(x&-x))
            bit[rn][x]++;
}
int get_count(int r,int x)
{
    int sum=0;
    for(;x>0;x-=(x&(-x)))
        sum+=bit[r][x];
    return sum;
}
bool check(int l,int r,int n)
{
    int odd=0; 
    for(int i=0;i<26;i++)
    {
        if((get_count(i,r)-get_count(i,l-1))%2!=0)
            odd++;
        if(odd>1)
            return false;
    }
    return true;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,q;
    scanf("%d %d",&n,&q);
    scanf("%s",st);
    // printf("%s %d\n",st,n);
    init(n);
    for(int i=0;i<n;i++)
    {
        // printf("%d %c\n",i,st[i]);
        update_bit(i+1,st[i],n,true);
    }
    int a,b,c;
    char d;
    for(int i=0;i<q;i++)
    {
        scanf("%d",&a);
        switch(a)
        {
            case 2:
                scanf("%d %d",&b,&c);
                if(check(b,c,n))
                    printf("yes\n");
                else
                    printf("no\n");
                break;
            case 1:
                scanf("%d %c",&b,&d);
                update_bit(b,d,n);
                break;
        }
    }
}