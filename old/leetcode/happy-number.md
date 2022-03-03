## [Problem](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3284/)

Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

## Solution

```cpp
class Solution {
public:
    int get_next_num(int n) {
        int next_num = 0;
        int digit = 0;
        while(n > 0) {
            digit = n % 10;
            n = n / 10;
            next_num += (digit * digit);
        }
        return next_num;
    }
    
    bool isHappy(int n) {
        unordered_map<int, int> table;
        while(n!=1 && table.find(n) == table.end()) {
            table[n] = get_next_num(n);
            n = table[n];
        }
        if (n == 1)
            return true;
        return false;
    }
};
```