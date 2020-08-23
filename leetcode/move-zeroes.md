## Problem

[move-zeroes](https://leetcode.com/problems/move-zeroes/)

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

## Solution in go

- count denotes index just in front of last non-zero number
- Keep replacing count with new non-zeroes and increment count
- set remaining array to zero

```go
func moveZeroes(nums []int)  {
    count := 0
    for _, num := range nums {
        if num !=0 {
            nums[count] = num
            count++
        }
    }
    for count < len(nums) {
        nums[count] = 0
        count ++
    }
}
```