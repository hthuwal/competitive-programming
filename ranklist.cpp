#include<iostream>
using namespace std;
int main()
{
    long long int t,n,s,x,count;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        x=(n*(n+1))/2;
        x=x-s;
        count=0;
        while(x>0)
        {
            count++;
            x=x-n+1;
            n--;
        }
        cout<<count<<endl;
    }
    return 0;
}
