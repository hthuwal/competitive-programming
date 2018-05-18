#include<iostream>
using namespace std;
int main()
{
    int  a,b;
    while(1)
    {
        cin >> a >>b;
        if (a==-1 && b==-1)
            break;
        else if(a==0 && b==0)
            cout << 0 <<endl;
        else if(a==b)
        {
            cout << 1 <<endl;
        }
        else if(a>=b)
        {
            b=b+1;
            if(a%b==0)
                cout<<a/b<<endl;
            else
                cout<<(a/b)+1<<endl;
        }
        else
        {
            a=a+1;
            if(b%a==0)
                cout<<b/a<<endl;
            else
                cout<<(b/a)+1<<endl;
        }
    }
    return 0;
}
