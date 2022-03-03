#include<iostream>
using namespace std;
int main()
{
    int t,r,c;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        if(r>c)
        {
            if(c%2==0)
            {
                cout<<"U"<<endl;
            }
            else
            {
                cout<<"D"<<endl;
            }
        }
        else
        {
            if(r%2==0)
            {
                cout<<"L"<<endl;
            }
            else
            {
                cout<<"R"<<endl;
            }
        }
    }
    return 0;
}
