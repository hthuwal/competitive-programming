#include <cstdio>
typedef struct duo{
    int o;
    int c;
} duo;

#define N 30300
#define T 10
char brackets[N];
duo st[6*N],temp;

void create(int ti,int l,int r)
{
    if(l==r)
    {
        if(brackets[l]=='(')
        {
            st[ti].o=1;
            st[ti].c=0;
        }else
        {
            st[ti].o=0;
            st[ti].c=1;
        }
    }
    else 
    {
        int mid = (l+r)>>1;
        int c1 = ti<<1;
        int c2 = c1|1;
        create(c1,l,mid);
        create(c2,mid+1,r);
        if(st[c1].o<=st[c2].c)
        {
            st[ti].o=0;
            st[ti].c=st[c2].c-st[c1].o;
        }
        else{
            st[ti].c=0;
            st[ti].o=st[c1].o-st[c2].c;
        }
        st[ti].o+=st[c2].o;
        st[ti].c+=st[c1].c;
    }
}
void update(int ti,int l,int r,int x)
{
    // printf("%d %d %d %d\n",ti,l,r,x);
    if(x<l || x>r) return;
    if(l==r && l==x)
    {
        st[ti].o = 1-st[ti].o;
        st[ti].c = 1-st[ti].c;
    }
    else{
        int mid = (l+r)>>1;
        int c1 = ti<<1;
        int c2 = c1|1;
        update(c1,l,mid,x);
        update(c2,mid+1,r,x);
        if(st[c1].o<=st[c2].c)
        {
            st[ti].o=0;
            st[ti].c=st[c2].c-st[c1].o;
        }
        else{
            st[ti].c=0;
            st[ti].o=st[c1].o-st[c2].c;
        }
        st[ti].o+=st[c2].o;
        st[ti].c+=st[c1].c;
    }
}
void print(int n)
{
     for(int i=0;i<=2*n-1;i++)
        {
            printf("%d,%d | ",st[i].o,st[i].c);
        }
    printf("\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,x,q;
    for(int t=1;t<=T;t++)
    {
        printf("Test %d:\n",t);
        scanf("%d",&n);
        scanf("%s",brackets);
        create(1,0,n-1);
       
        
        for(scanf("%d",&q);q--;)
        {
            // print(n);
            scanf("%d",&x);
            if(x==0)
            {
                if(st[1].o==0 && st[1].c==0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
                update(1,0,n-1,x-1);
        }
        
    }
}