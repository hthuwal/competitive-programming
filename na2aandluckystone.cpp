#include<iostream>
using namespace std;
int main(){
    int n,hc,temp;
    cin>>n;
    while(n--){
        cin>>hc;
        temp=hc;
        a:
        while(hc!=0){
            if(hc%10!=0)
                break;
            else
                hc=hc/10;
        }

        if(hc%10==5)
        {
            temp=temp*4;
            hc=temp;
            goto a;
        }
        cout<<temp<<endl;
    }
}
