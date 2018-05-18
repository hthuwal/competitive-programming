#include <cstdio>
using namespace std;
int rec(int s1,int s2,int n,int b)
{
    if(n<0) return 0;
    else if(n<b || n==0) return s2;
    else
    {
        int p = rec(s1+1,s2,n-1,b);
        int q = rec(s1,s2+s1,n-b,b);
        return p>q?p:q;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int t,n,b;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d %d",&n,&b);
        printf("%d\n",rec(0,0,n,b));
    }
} 