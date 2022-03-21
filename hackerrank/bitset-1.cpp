/**
 * https://www.hackerrank.com/challenges/bitset-1/problem
 **/
#include <bits/stdc++.h>

using namespace std;

unsigned mod(unsigned n, unsigned m) {
    return (n & (m - 1));
}

// Floyd's Cycle Detection
int detect_cycle(vector<unsigned> &values) {
    int n = values.size();
    int i = 0;
    for (; i < n; i++) {
        if (2 * i + 1 > n) {
            return n;
        }

        if (values[i] == values[2 * i + 1]) {
            break;
        }
    }

    unsigned joint_value = values[i];
    int occur = 0;
    for (i = 0; i < n; i++) {
        if (values[i] == joint_value) {
            if (occur == 0) {
                occur++;
            } else if (occur == 1) {
                break;
            }
        }
    }
    return i;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    unsigned N, S, P, Q;
    cin >> N >> S >> P >> Q;
    vector<unsigned> values(N, 0);
    unsigned M = 1 << 31;

    S = mod(S, M);
    P = mod(P, M);
    Q = mod(Q, M);
    values[0] = (S);
    for (int i = 1; i <= N - 1; i++) {
        S = mod(mod((S * P), M) + Q, M);
        values[i] = S;
    }
    cout << detect_cycle(values) << endl;
}
