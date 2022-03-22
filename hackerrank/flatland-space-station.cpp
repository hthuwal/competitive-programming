/**
 * https://www.hackerrank.com/challenges/flatland-space-stations
 **/
#include <bits/stdc++.h>

using namespace std;

int flatlandSpaceStations(int n, vector<int> &c) {
    sort(c.begin(), c.end());
    int ans = c[0];
    for (int i = 1; i < c.size(); i++) {
        int mid = (c[i] + c[i - 1]) / 2;
        if (mid == c[i - 1])
            continue;
        ans = std::max(ans, std::min(c[i] - mid, mid - c[i - 1]));
    }
    ans = std::max(ans, n - 1 - c[c.size() - 1]);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    cout << flatlandSpaceStations(n, c);
}