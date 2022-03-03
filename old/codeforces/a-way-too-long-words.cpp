#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    int n, l;
    cin>>n;
    while (n--) {
        cin>>s;
        l = s.length();
        if(l <= 10) {
            cout<<s<<endl;
        }
        else {
            cout<<s[0]<<l-2<<s[l-1]<<endl;
        }
    }
}