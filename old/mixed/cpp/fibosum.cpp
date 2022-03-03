#include<iostream>
using namespace std;
#define x 1000000007;
long long int a[100000000];
int main()
{
    int i;
    a[0]=0;
    a[1]=1;
    for(i=2;i<80;i++)
    {
       a[i]=a[i-1]+a[i-2]+1;
       cout<<a[i]<<" ";
    }
    cout<<endl;
}
