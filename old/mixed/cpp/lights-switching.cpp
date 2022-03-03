#include <cstdio>
#define N 111111
#define lli long long int
lli tree[6*N];
lli lazy[6*N];

void init(int n)
{
    for(int i=0;i<6*n;i++)
    {
        tree[i]=0;
        lazy[i]=0;
    }
}
void print(int n)
{
    for(int i=0;i<2*n;i++)
        printf("%lld ",tree[i]);
    printf("\n");
}

lli getsum(lli si,lli ai,lli aj,lli i,lli j)
{
    if(lazy[si]!=0)
    {
        if(lazy[si]%2!=0)
        {
            tree[si]=(aj-ai+1-tree[si]);
            if(ai!=aj)
            {
                lazy[2*si]+=lazy[si];
                lazy[2*si+1]+=lazy[si];
            }
        }
        lazy[si]=0;
    }
    if(ai>=i && aj<=j)
        return tree[si];
    if(j<ai || i>aj)
        return 0;
    lli mid = (ai+aj)/2;
    return getsum(2*si,ai,mid,i,j)+getsum(2*si+1,mid+1,aj,i,j);
}
void update(lli si,lli ai, lli aj, lli i, lli j)
{
    if(lazy[si]!=0)
    {
        if(lazy[si]%2!=0)
        {
            tree[si]=(aj-ai+1-tree[si]);
            if(ai!=aj)
            {
                lazy[2*si]+=lazy[si];
                lazy[2*si+1]+=lazy[si];
            }
        }
        lazy[si]=0;
    }
    if(j<ai || i >aj || ai > aj)
        return;
    if(ai>=i && aj<=j)
    {
        tree[si]=(aj-ai+1-tree[si]);
        if(aj!=ai)
        {
            lazy[2*si]++;
            lazy[2*si+1]++; 
        }
    }
    else{
        lli mid = (ai+aj)>>1;
        update(2*si,ai,mid,i,j);
        update(2*si+1,mid+1,aj,i,j);
        tree[si]=tree[2*si]+tree[2*si+1];
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    lli n,m,a,b,c;
    scanf("%lld %lld",&n,&m);
    init(n);
    // print(n);
    while(m--)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==0)
            update(1,0,n-1,b,c);
        else
            printf("%lld\n",getsum(1,0,n-1,b,c));
        // print(n);
    }
}