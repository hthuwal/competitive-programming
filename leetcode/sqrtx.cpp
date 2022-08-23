/* -------------------------------------------------------------------------- */
/*                    https://leetcode.com/problems/sqrtx/                    */
/* -------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

class Solution {
   public:
    int mySqrt(int x) {
        long start = 0;
        long end = x / 2 + 1;
        long mid;
        long sq;

        while (start <= end) {
            mid = start + (end - start) / 2;
            sq = mid * mid;
            if (sq == x) {
                return mid;
            } else if (sq < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return start - 1;
    }
};

int main() { cout << Solution().mySqrt(2147395599) << "\n"; }