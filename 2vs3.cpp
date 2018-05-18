#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int create(int tree[],int si,char a[],int sl,int sh)
{
    if(sl==sh)
    {
        tree[si]=a[sl]-'0';
        return tree[si];
    }
    else{
        int mid = (sl+sh)/2;
        int left = create(tree,2*si,a,sl,mid)%3;
        int right = create(tree,2*si+1,a,mid+1,sh)%3;
        tree[si]=((int)(pow(2,abs(sh-mid))*left)%3+ right)%3;
        return tree[si];
    }
}
int update(int tree[],int si,char a[],int sl,int sh,int i)
{
    if(i<sl || i>sh)
        return 0;
    else
    {
        tree[si]=(tree[si]+(int)pow(2,sh-i)%3)%3;
        if(sl!=sh)
        {
            int mid=(sl+sh)/2;
            update(tree,2*si,a,sl,mid,i);
            update(tree,2*si+1,a,mid+1,sh,i);
        }
    }
}
int getans(int tree[],int si,char a[],int sl,int sh,int x,int y)
{
    if(x<=sl && y>=sh)
        return tree[si];
    if(x>sh || y <sl)
        return 0;
    int mid = (sl+sh)/2;
    int left = getans(tree,2*si,a,sl,mid,x,y);
    int right = getans(tree,2*si+1,a,mid+1,sh,x,y);
    if(y<=sh)
        return ((int)(pow(2,abs(y-mid))*left)%3 + right)%3;
    else
        return ((int)(pow(2,abs(sh-mid))*left)%3 + right)%3;

}
int main()
{
    freopen("in.txt","r",stdin);
    int n,t=0,a,b,c;
    char hc[111111];
    int tree [(int)(2*pow(2,ceil(log2(111111)))-1)];
    scanf("%d",&n);
    scanf("%s",hc);
    create(tree,1,hc,0,n-1);
    // scanf("%d",&t);
    for(int i=0;i<100;i++)
        cout<<tree[i]<<" ";
    while(t--)
    {
        scanf("%d",&a);
        if(a==0)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",getans(tree,1,hc,0,n-1,a,b));
        }
        else
        {
            scanf("%d",&b);
            if(hc[b]=='0')
            {
                hc[b]='1';
                update(tree,1,hc,0,n-1,b);
            }
        }
    }
}
