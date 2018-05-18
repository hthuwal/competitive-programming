#include<iostream>
#include<cstdlib>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
    int hc[1100],jp[1100],t,n,k,i,j,flag;
    cin >>t;
    while(t--)
    {
        cin >>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>hc[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>jp[i];
        }
        qsort(hc,n,sizeof(int),compare);
        qsort(jp,n,sizeof(int),compare);
        for(i=0,j=n-1,flag=1;i<n&&j>=0;i++,j--)
        {
            if((hc[i]+jp[j])<k)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
