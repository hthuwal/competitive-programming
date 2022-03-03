/**
 * https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/rook-path-142e55ee/
 **/
#include<bits/stdc++.h>
#define lli long long int
#define vi vector<Triplet>
#define vvi vector<vi>
#define MOD 1000000007
using namespace std;

class Triplet{
    public:
        lli num_w; // number of ways to reach this cell
        lli sum_l; // sum of number of ways to reach the cells to the left (till an obstacle) of the current cell.
        lli sum_u; // sum of number of ways to reach the cells to the top (till an obstacle) of the current cell.
        void set(lli w, lli l, lli u) {
            num_w = w;
            sum_l = l;
            sum_u = u;
        }
};

void solve_test_case() {
    int n, m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0; i<n; i++)
        cin>>grid[i];
    
    vvi dp(n, vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            Triplet &ct = dp[i][j];
            if(i==0 && j==0) {
                ct.set(1, 1, 1);
                continue;
            }
            
            if(grid[i][j] == '*') {
                ct.set(0, 0, 0);
                continue;
            }

            lli sum_l = 0;
            lli sum_u = 0;
            if(j!=0) {
                sum_l = dp[i][j-1].sum_l;
            }

            if(i!=0) {
                sum_u = dp[i-1][j].sum_u;
            }

            lli num_ways = (sum_l + sum_u) % MOD;
            ct.set(num_ways, (num_ways + sum_l) % MOD, (sum_u + num_ways) % MOD);
        }
    }
    cout<<dp[n-1][m-1].num_w<<"\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve_test_case();
    }
}