/* -------------------------------------------------------------------------- */
/*            https://leetcode.com/problems/n-th-tribonacci-number/           */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*               https://leetcode.com/problems/fibonacci-number               */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }

        int fi2 = 0;
        int fi1 = 1;
        int fi;
        for (int i = 2; i <= n; i++) {
            fi = fi2 + fi1;
            fi2 = fi1;
            fi1 = fi;
        }

        return fi;
    }

    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 1;
        }

        int fi3 = 0;
        int fi2 = 1;
        int fi1 = 1;
        int fi;
        for (int i = 3; i <= n; i++) {
            fi = fi3 + fi2 + fi1;
            fi3 = fi2;
            fi2 = fi1;
            fi1 = fi;
        }

        return fi;
    }
};

int main() {
    cout << Solution().fib(30) << "\n";
    cout << Solution().tribonacci(30) << "\n";
}