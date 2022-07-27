/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/count-primes/                */
/* -------------------------------------------------------------------------- */
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    Solution() {
    }

    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        vector<int> primes(n + 1, 0);

        for (int i = 1; i < n + 1; i++) {
            primes[i] = i;
        }

        primes[0] = -1;
        primes[1] = -1;
        for (int i = 2; i * i < n + 1; i++) {
            if (primes[i] != -1) {
                for (int j = i + i; j < n + 1; j += i) {
                    primes[j] = -1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (primes[i] != -1) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    cout << Solution().countPrimes(100);
}