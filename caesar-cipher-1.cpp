#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    string s;
    int n;
    int k;
    int m;

    cin>>n;
    cin>>s;
    cin>>k;

    for(int i=0;i<n;i++){

        if( s[i]<='z' && s[i]>='a'){
            m=s[i]+k-97;
            m=97+m%26;
            s[i]=m;
        }
        if(s[i]<='Z' && s[i]>='A' ){
            m=s[i]+k-65;
            m=65+m%26   ;
            s[i]=m;
        }
    }
    cout<<s;
}
