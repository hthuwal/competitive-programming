#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long long int t,p,ans,b;
    string a;
    cin >> t;
    while(t--)
    {
        cin >>a;
        cin >>b;
        p=a[a.length()-1]-'0';
        if(b==0)
            cout << 1<<endl;
        else
        {
        ans=1;
        b=4+b%4;
        while(b--)
        {
            ans=ans*p;
        }
        cout <<ans%10<<'\n';
        }
    }
    return 0;
}


