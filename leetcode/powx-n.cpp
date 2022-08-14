/* -------------------------------------------------------------------------- */
/*                    https://leetcode.com/problems/powx-n                    */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    double myPow(double x, int n) {
        double ans = 1;
        while (n != 0) {
            // If the power is odd you have to
            // multiply the candidate once to the answer
            if (n & 1 == 1) {
                if (n > 0) {
                    ans = ans * x;
                } else {
                    ans = ans / x;
                }
            }

            x = x * x;  // Then square the cadidate
            n = n / 2;  // Power becomes half
        }
        return ans;
    }
};