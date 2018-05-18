#include<iostream>
using namespace std;
int hc[100005];
int main()
{
    int n,k,q,i,x;
    cin >>n>>k>>q;
    for(i=0;i<n;i++)
    {
        cin >>hc[i];
    }
    k=k%n;
    while(q--)
    {
        cin >>x;
        cout << hc[(n-k+x)%n]<<endl;
    }
    return 0;
}
