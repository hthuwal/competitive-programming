#include<algorithm>
#include<iostream>
int a[10000000];
int sum[3][10000000];
using namespace std;
int main()
{
    int t,n,w,i,count,j,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>w;
        count=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sum[0][0]=a[0];
        if(w == 1)
            count++;
        for(i=1;i<n;i++)
        {
            sum[0][i]=sum[0][i-1]+a[i];
            if(i+1 >=w && sum[0][i]%(i+1)==0)
                count++;
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i>j)
                {
                    sum[1][j]=0;
                }
                else if(j-i+1>=w)
                {
                    sum[1][j]=sum[0][j]-a[i-1];
                    if((sum[1][j]*2)%(j-i+1)==0)
                    {
                        count++;
                    }
                }
                else
                {
                    sum[1][j]=sum[0][j]-a[i-1];
                }
                sum[0][j]=sum[1][j];
            }
        }
        cout<<count<<endl;
    }
}
