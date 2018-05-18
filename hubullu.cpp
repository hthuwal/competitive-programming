#include<iostream>
using namespace std;
int main()
{
    long long int t,a,b;
    cin>>t;
    while(t--)
    {
        cin >>a>>b;
        if(b==0)
            cout <<"Airborne wins."<<endl;
        else
            cout <<"Pagfloyd wins."<<endl;
    }
}
