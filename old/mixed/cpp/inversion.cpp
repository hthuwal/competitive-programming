#include<iostream>
#define x 1000010
using namespace std;
int main()
{
    int a[x]={0},n,temp,i,j,maxx,count1;
    cin >>n;
    for(i=1,maxx=0;i<=n;i++)
    {
        cin >>temp;
        if(temp>maxx)
            maxx=temp;
        a[temp]=i;
    }
    for(j=1,count1=0;j<=n;j++)
    {
        cin>>temp;
        for(i=temp+1;i<=maxx;i++)
        {
            if(a[i]!=0&&a[i]<j)
                count1++;
        }
    }
    cout<<count1;
    return 0;
}
