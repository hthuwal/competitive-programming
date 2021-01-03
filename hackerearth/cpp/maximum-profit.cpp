/**
 * https://www.hackerearth.com/problem/algorithm/maximum-profit-5-c3c2ce7c/description/
 **/
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
    lli t, n, x, k;
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        set<lli> coins;
        for (int i = 0; i < n; i++)
        {   
            cin>>x;
            coins.insert(x);
        }

        int count = 0;
        lli ans = 0;
        for(auto it = coins.rbegin(); it != coins.rend() && count < k; it++, count++) {
            ans += (*it);
        }
        cout<<ans<<"\n";
    }
}