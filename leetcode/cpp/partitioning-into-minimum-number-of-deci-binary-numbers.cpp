// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    // The minimum number of partitions is the highest digit in the string
    // Because you need that many 1's in that position to obtain that digit
    int minPartitions(string n) {
        int max = 0;
        for (const auto& c : n) {
            int digit = c - '0';
            if (digit == 9) {
                return 9;
            }
            if (digit > max) {
                max = digit;
            }
        }
        return max;
    }
};

int main() { cout << Solution().minPartitions("1234123491237846123784"); }