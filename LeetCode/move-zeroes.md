## Problem

[move-zeroes]()

## Solution in Cpp

- Keep a pointer to the first zero from the beginning. 
- Iterate over the list and if encountered a number that is after the zero pointer, swap it with the number and increment zero pointer to next zero in the list.

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int target = 0;
        int numsSize = nums.size();
        for(int i=0; i<numsSize; i++) {
            while(target< numsSize && nums[target] != 0)
                target += 1;

            if (target == numsSize)
                break;

            if (nums[i] != 0 && target < i) {
                nums[target] = nums[i];
                nums[i] = 0;
            }
        }
    }
};
```