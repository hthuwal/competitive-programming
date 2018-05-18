#include <iostream>

using namespace std;

int main()
{
    long long int t,ans,a,b;
    cin >> t;
    while(t--)
    {
        cin >>a >>b;
        if(b==0)
            cout << 1<<endl;
        else
        {
        ans=1;
        b=4+b%4;
        while(b--)
        {
            ans=ans*a;
        }
        cout <<ans%10<<'\n';
        }
    }
    return 0;
}
