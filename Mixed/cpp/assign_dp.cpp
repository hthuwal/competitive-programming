/**
dp[i]
i in binary form 1010010110101.... kth bit 1 implies kth subject taken
also number of students considered by dp[i]  = number of 1's in the binary representation of i
**/
/**
recurrence relation
f(Sn,subjects)=sum of all ( f(Sn-1,subjects-e) for eache e that Sn likes)
**/

/**Time Complexity**/
/*
    T(n) = 2^n * ( n + nC0 + nC1 + nC2 + nC3 + nC4 + . ... . nCn)
         = 2^n * (n + 2^n)
         = 2^(2n)
*/

#include <cstdio>
#define isone(x,i) ((x>>i)&1)
int main()
{
    // freopen("in.txt","r",stdin);
    int a[25][25],c,n;
    for(scanf("%d",&c);c--;)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        
        long long int dp[1<<n]={0};
        dp[0]=1;// i = 000000000000000000000... none of the subject is taken only 1 way
        for(int i=0;i<(1<<n);i++)
        {
            /*kaunse student ki baat ho ri hai? Student number = number of 1's in binary representation of i*/
            int Sc=0;
            for(int j=0;j<n;j++)
            {
                Sc+=isone(i,j);
            }

            /*Implementing Recurrence relation**/
            for(int j=0;j<n;j++)//of all possible subjects
            {
                if(a[Sc-1][j] && isone(i,j))//if current student likes this subject and current permuation allows this subject to be taken
                {
                    /*find sum of all possible ways of having Sc-1 students take remaining subjects => jth bit must be 0 in the binary represenation of i*/
                    dp[i]+=dp[i & ~(1<<j)];
                }
            }
        }
        printf("%lld\n",dp[(1<<n) - 1]);
    }
}
