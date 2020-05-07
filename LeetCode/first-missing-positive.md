## first-missing-positive

[Problem](https://leetcode.com/problems/first-missing-positive/submissions/)

## O(n) time and O(n) space solution

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        count = {}
        for each in nums:
            if each > 0:
                if each not in count:
                    count[each] = True

        values = list(count.keys())
        if len(values) == 0:
            return 1

        lowest = min(values)

        if lowest != 1:
            return 1
        else:
            i = 2
            while(True):
                if i in count:
                    i += 1
                else:
                    return i
```

## Apparently there is a O(n) and O(1) solution :thinking:

- The idea is the given an array of size n. If all positive integers are present than they must be 1,2,3 .... n
- So we use the list itself to keep track of the numbers.

Input: `[3, 5, 7, -1, 1, 2, 1]`

1. If a number is negative or greater than the size of the list --> Ignore it.
2. Else the number should be part of the array.
    + If the number is at correct place, i.e. arr[i] = i+1. For example: integer at 5th place (i = 4) == 5 --> Already at correct place. Skipt it.
    + Else, swap the arr[i] with the number that is correct place arr[i]-1 and then check for the new number again.
        * Keep in mind the infinite loop case arr[i] == arr[i]-1 (move ahead this integer occured twice.)

At this point the array would be like `[1, 5, 3, -1, 5, 7, 1]`

3. Answer is the first location which does not contain itself as the value.
    - Note: Ignore negative numbers.
    ```
    Numbers =   `[1, 5, 3, -1, 5, 7, 1]`
    Positions =   1, 2, 3,     4, 5, 6 
    ```

### Code: C++

```cpp
class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int l, h;
        
        if (nums.size() == 0)
            return 1;
        
        for(int i=0; i< nums.size();i++) {
            if(nums[i] <= 0)
                continue;
            
            if(nums[i] == i+1)
                continue;
            
            if(nums[i] <= nums.size()) {
                l = i;
                h = nums[i]-1;
                if (nums[l] != nums[h]) {
                    swap(nums, i, nums[i]-1);
                    i--;
                }
            } 
        }
        
        int nonpos = 0;
        int next_num = 0;
        for(int i=0; i<nums.size(); i++) {
            next_num = i + 1 - nonpos;
            if (nums[i] <= 0)
                nonpos ++;
            else if (nums[i] != next_num)
                return next_num;
        }
        
        return nums.size() + 1 - nonpos;
    }
};
```

### Code: Python

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 1
        i = 0
        while i < len(nums):
            if nums[i] <= 0:
                i += 1
                continue
            if nums[i] == i + 1:
                i += 1
                continue
            if nums[i] <= i + 1:
                me = i
                target = nums[i] - 1
                if nums[me] != nums[target]:
                    nums[me], nums[target] = nums[target], nums[me]
                    i -= 1
            i += 1

        nonpos = 0
        next_num = 0
        for i in range(len(nums)):
            next_num = i + 1 - nonpos
            if nums[i] <= 0:
                nonpos += 1
            elif nums[i] != next_num:
                return next_num

        return len(nums) + 1 - nonpos
```