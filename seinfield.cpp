#include<iostream>
using namespace std;
int main()
{
    int t=0,a,b;
    string s;
    while(1)
    {
        a=0;
        b=0;
        cin>>s;
        if(s[0]=='-')
            break;
        else
        {
            t++;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='{')
                    a++;
                else if(s[i]=='}'&&a!=0)
                {
                    a--;
                }
                else
                    b++;
            }
        }
         if(a % 2 == 0)
            {
                cout << t << ". " << (a+b)/2 << '\n';
            }
            else
            {
                cout << t << ". " << (a+b+2)/2 << '\n';
            }
    }
    return 0;
}
