/* https://codeforces.com/problemset/problem/1243/B1 */

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

string areOneSwapDifferent(string a, string b) {
    vi differ_at;
    for(int i=0;i<a.length();i++) {
        if(a[i]!=b[i])
            differ_at.push_back(i);
    }
    if(differ_at.size() != 2)
        return "No";

    if(a[differ_at[0]] == a[differ_at[1]] and b[differ_at[0]] == b[differ_at[1]])
        return "Yes";
    
    return "No";
}

int main()
{
    string a, b;
    int t,n;
    cin.sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>a;
        cin>>b;
        cout<<areOneSwapDifferent(a,b)<<"\n";
    }
}

