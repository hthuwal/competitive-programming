#include <cstdio>
#include <climits>
using namespace std;
int main()
{
   freopen("in.txt","r",stdin);
    int t;
    for(scanf("%d",&t);t--;)
    {
        char b[1111111];
        char a[1111111];
        scanf("%s",b);
        int j=0;
        for(int i=0;b[i]!='\0';i++)
        {
            if(b[i]!='=')
                a[j++]=b[i];
        }
        a[j]='\0';
        int ans=0;
        int l=0;
        char prev='-';
        for(int i=0;a[i]!='\0';i++)
        {
                if(a[i]!=prev)
                {
                    if(l>ans)
                        ans=l;
                    // printf("%d %d\n",ans,l);
                    l=1;
                }else
                    l++;
                prev = a[i];
        }        
        if(l>ans)
            ans=l;
        printf("%d\n",ans+1);
    }
}