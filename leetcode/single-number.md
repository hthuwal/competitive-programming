## [Problem](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3283/)

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

## Solution

### O(n) Space, O(n) Time solution

Use HashMap to store count of each integer.

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> counts;

        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            counts[nums[i]] += 1;
        }

        for(int i=0; i<nums.size(); i++) {
            if(counts[nums[i]] == 1)
                return nums[i];
        }
        // Code would never reach here.
        return 0;
    }
};
```

### O(1) Space, O(n) Time Solution

- XOR `(^)` opertor :man_facepalming:
- `a ^ a = 0`
- `0 ^ a = a`



```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
```

