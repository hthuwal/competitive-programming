/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/power-of-two                 */
/* -------------------------------------------------------------------------- */

#include <iostream>

class Solution {
   public:
    // Counting number of set bits
    bool isPowerOfTwo(long n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            if (count > 1) {
                return false;
            }
            n = n >> 1;
        }
        if (count == 0) {
            return false;
        }
        return true;
    }

    // x & (x-1) == 0 for powers of 2
    bool isPowerOfTwo(long n) { return n && !(n & (n - 1)); }
};