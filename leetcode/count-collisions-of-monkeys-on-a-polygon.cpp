/* -------------------------------------------------------------------------- */
/*   https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon   */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

#define M 1000000007

class Solution {
   public:
    long powOf2(long n) {
        long ans = 1;
        long x = 2;
        while (n != 0) {
            if ((n & 1) == 1) {
                ans = (ans * x) % M;
            }
            x = (x * x) % M;
            n = n >> 1;
        }
        return ans;
    }

    // Each vertex has a monkey.
    // Each monkey has two choices.
    // So number of possible moves 2^n
    // Number of moves where there is no conflict = 2
    //    - All move clockwise
    //    - All move counter clockwise
    // Number of moves which result in at least one collision = 2^n - 2
    int monkeyMove(int n) { return (powOf2(n) - 2 + M) % M; }
};

int main() {
    Solution s;
    cout << s.monkeyMove(500000003) << endl;
}