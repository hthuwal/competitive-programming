#include<iostream>
using namespace std;
int dr(int x)
{
    int i,j;
    for(i=0;(i)*(2*i+1)<x;i++)
    {
    }
    j=x-((i-1)*(2*i-1));
    if(j<2*i)
    {
        return j;
    }
    else
    {
        return 2*i-(j%(2*i));
    }
}
int nr(int x)
{
    int i,j;
    for(i=1;(i)*(2*i-1)<x;i++)
    {
    }
    j=x-((i-1)*(2*i-3));
    if(j<(2*i-1))
    {
        return j;
    }
    else
    {
        return (2*i-1)-(j%((2*i-1)));
    }
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"TERM "<<n<<" IS "<<nr(n)<<"/"<<dr(n)<<endl;
    }
    return 0;
}
