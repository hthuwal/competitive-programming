#include<iostream>
using namespace std;
int main()
{
    string front,back,left,right,top,bottom;
    int t,flag;
    cin>>t;
    while(t--){
        cin>>front>>back>>left>>right>>top>>bottom;
        flag=0;
        if(left == top || left == bottom){
            if(left == front || left == back){
                flag=1;
            }
        }
        if(right == top || right == bottom){
            if(right == front || right == back){
                flag=1;
            }
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
