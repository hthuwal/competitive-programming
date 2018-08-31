#include <cstdio>
#include <cstring>
#define lli int
#define M 11380
lli dp[15][15][15][35];

lli dpp(lli curl, lli sqr, lli para, lli d)
{
    /*no regex possible with -ve depth*/
    if(d < 0)
        return 0;
    /* only one regex possible with no curl, params or square brackets i.e empty string*/
    if(curl+sqr+para == 0)
        return 1;
    
    lli &ans = dp[curl][sqr][para][d];

    /*if answer is not memoized i.e not previously calculatd*/
    if(ans==-1)
    {
        ans = 0;

        /*make all possible ending with curl brackets of depth d-1
        the rest must make regex of depth d*/
        for(int i=0;i<curl;i++)
        for(int j=0;j<=sqr;j++)
        for(int k=0;k<=para;k++)
        ans = (ans + dpp(i,j,k,d-1)*dpp(curl-i-1, sqr-j, para-k,d) % M)%M;

        /*make all possible ending with square brackets of depth d-1
        the rest must make regex of depth d*/
        for(int j=0;j<sqr;j++)
        for(int k=0;k<=para;k++)
        ans = (ans + dpp(0,j,k,d-1)*dpp(curl,sqr-j-1,para-k,d) % M ) % M;

        /*make all possible ending with paranthesis of depth d-1
        the rest must make regex of depth d*/
        for(int k=0;k<para;k++)
        ans = (ans + dpp(0,0,k,d-1)*dpp(curl,sqr,para-k-1,d) % M ) % M;

    }
    return ans;
}

int main()
{
    memset(dp,-1, sizeof(dp));
    int c,s,p,d;
    for(int i=0;i<10;i++)
    {
        scanf("%d %d %d %d",&c,&s,&p,&d);
        lli ans = dpp(c,s,p,d)-dpp(c,s,p,d-1);
        if(ans < 0)
            ans += M;
        printf("%d\n",ans);
    }
}