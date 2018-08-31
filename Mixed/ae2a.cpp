/*
After n = 545 and k = 1908 answer is 0 how?
*/
#include <cstdio>
#include <iostream>

double dyn[1000][6000];
inline void fastscan(int &x)
{  
    register char c=0;
    while (c<33) c=getchar_unlocked();
    x=0;
    while (c>33)
    {
        x=x*10+c-'0';
        c=getchar_unlocked();
    }
}

void dp()
{
    dyn[1][0]=0;
    for(int i=1;i<=6;i++)
    {
        dyn[1][i] = 1.0/6.0;
    }
    for(int i=2;i<1000;i++)
    {
        dyn[i][0]=0;
        for(int j=1;j<=6*i;j++)
        {
            int die = j<6 ? j :6;
            dyn[i][j]=0;
            for(;die>=1;die--)
            {
                dyn[i][j]+=(1/6.0)*dyn[i-1][j-die];
            }

        }
    }
}
int main()
{
    int t,n,k;
    dp();
    fastscan(t);
    for(int i=0;i<t;i++)
    {
        fastscan(n); //n
        fastscan(k); //k
        if(k>999 || n>5999 || k< n*1 || k>n*6)
            printf("0\n");
        else
            printf("%d\n",(int)(dyn[n][k]*100));
    }
}