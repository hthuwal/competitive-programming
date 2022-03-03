    #include<iostream>
    #include<cstdio>
    using namespace std;
    int hc(int a[], int n)
    {
        int ans[n][n],smoke[n][n],i,j,k,l,temp;
        for(i=0;i<n;i++)
        {
            ans[i][i]=a[i];
            smoke[i][i]=0;
        }
        for(l=0;l<n-1;l++)
        {
        for(i=0;i<n-1;i++)
        {
            j=i+l+1;
            if(j==n)
                break;
            smoke[i][j]=1000000000;
            for(k=i;k<j;k++)
            {
                temp=smoke[i][k]+smoke[k+1][j]+(ans[i][k]*ans[k+1][j]);
                if(temp<smoke[i][j])
                {
                    smoke[i][j]=temp;
                    ans[i][j]=(ans[i][k]+ans[k+1][j])%100;
                }
            }
        }
        }
        return smoke[0][n-1];
    }
    int main()
    {
        int n,i,a[110];
        while(scanf("%d",&n)!=EOF)
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
            printf("%d\n",hc(a,n));
        }
        return 0;
    }
