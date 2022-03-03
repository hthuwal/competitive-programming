#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, a, b, c;
    cin>>n;
    int count = 0;
    while(n--) {
        cin>>a>>b>>c;
        if (a+b+c >= 2)
            count ++;
    }
    cout<<count;
}