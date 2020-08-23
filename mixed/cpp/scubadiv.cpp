#include <cstdio>
#include <cstring>
int ox[1001];
int ni[1001];
int w[1001];
int tanks=0;

int memo[22][80][1001];

int ans(int o,int n, int i)
{
    if(o<0) o = 0;
    if(n<0) n = 0;

    if(o<=0 && n<=0)
        return 0;
    else if(i<0)
        return -1;
    else{

        if(memo[o][n][i]!=-2)
            return memo[o][n][i];
            
        int take_i = -1;
        int not_take_i = -1;
        take_i = ans(o-ox[i], n-ni[i], i-1);
        take_i = take_i == -1 ? -1 : take_i + w[i];
        not_take_i = ans(o, n, i-1);

        if(take_i == -1)
        {
            memo[o][n][i] = not_take_i;     
            return memo[o][n][i];
        }
        if(not_take_i == -1)
        {
            memo[o][n][i] = take_i;     
            return memo[o][n][i];
        }
        memo[o][n][i] = take_i < not_take_i ? take_i : not_take_i; 
        return memo[o][n][i];
    }
}
int main()
{
    
    int t,n,m;
    for(scanf("%d",&t);t--;)
    {
        scanf("%d %d",&n,&m);
        scanf("%d",&tanks);
        for(int i=0;i<tanks;i++)
            scanf("%d %d %d",&ox[i],&ni[i],&w[i]);
        
        for(int i=0;i<22;i++)
            for(int j=0;j<80;j++)
                for(int k=0;k<1001; k++)
                    memo[i][j][k]=-2;
        printf("%d\n",ans(n,m,tanks-1));
    }
}