#include<iostream>
using namespace std;
int main()
{
    int n,i,temp;
    while(1)
    {
        cin >> n;
        if(n==-1)
            break;
        else
        {
            for(i=1;;i++)
            {
                temp=1+3*i*(i-1);
                if(temp==n)
                {
                    cout<<"Y"<<endl;
                    break;
                }
                else if(temp>n)
                {
                    cout<<"N"<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
