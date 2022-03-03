/**
 * https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/min-cost-2-fe2d3308/
 **/
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

void solve_test_case() {
    lli n, c10, c01;
    cin>>n>>c01>>c10;
    vector<int> bits(n);
    for(int i=0;i<n;i++) {
        cin>>bits[i];
    }

    lli cost_a = 0;
    int a = 0;
    lli cost_b = 0;
    int b = 1;
    
    for(int i=0;i<n;i++){
        if(bits[i] != a) {
            cost_a += bits[i] == 1? c10 : c01;
        }

        if(bits[i] != b) {
            cost_b += bits[i] == 1? c10 :  c01;
        }

        a ^= 1;
        b ^= 1;
    }
    cout<< (cost_a < cost_b ? cost_a : cost_b)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    
    while(t--){
        solve_test_case();
    }
}