/**
 * https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/alice-and-customer-satisfaction-b6dc3745/
 **/
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

bool isValid(vector<pair<lli, lli>> &ranges, lli rate) {
    for(auto range: ranges) {
        if (range.first * rate < range.second) {
            return false;
        }
    }
    return true;
}

lli solve(vector<pair<lli, lli>> &ranges, lli l, lli h) {
    while (l!=h) {
        lli m = l + (h-l) / 2;
        if (isValid(ranges, m)) {
            h = m;
        } else {
            l = m+1;
        }
    }
    return l;
}


void solve_test_case() {
    lli n, s, e, q;
    cin >> n;
    vector<pair<lli, lli>> ranges;
    for (size_t i = 0; i < n; i++)
    {
        cin>>s>>e>>q;
        ranges.push_back({e, q});
    }
    sort(ranges.begin(), ranges.end());
    for (size_t i = 1; i < n; i++)
        ranges[i].second += ranges[i-1].second;

    cout<<solve(ranges, 1, ranges[ranges.size()-1].second+1)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
        solve_test_case();
}