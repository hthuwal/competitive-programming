## [Problem](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3285/)

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

## Solution

### O(n): Kadane's Algorithm

```cpp
class Solution {
public:
    int kadane_max_positive_sum(vector<int>& nums) {
        int max_so_far = 0;
        int max_uptill_now = 0;
        for(int i=0; i<nums.size(); i++) {
            max_uptill_now += nums[i];
            if (max_uptill_now > max_so_far) 
                max_so_far = max_uptill_now;
            if (max_uptill_now < 0)
                max_uptill_now = 0;
        }
        return max_so_far;
    }

    int max_element_in_list(vector<int>& nums) {
        int max_in_list = INT_MIN;
        for(int i=0;i<nums.size(); i++) {
            if (nums[i] > max_in_list)
                max_in_list = nums[i];
        }
        return max_in_list;
    }

    int maxSubArray(vector<int>& nums) {
        int max_positive = kadane_max_positive_sum(nums);
        /**
         * If Kadane returned 0, there are two possibilities:
         *    1. All numbers are negative. In which case the answer is the largest negative nubmer. 
         *    2. A single number with value 0 exists. In which case answer is 0.
         * So we should find the maximum element in the array.
         */
        if (max_positive == 0) {
            return max_element_in_list(nums);
        }
        return max_positive;
    }
};
```

### O(nlogn): Divide and Conquer Algorithm

```python
class Maximum:
    """
    max_sum_beg:  Maximum sum of the subarray that must start at the beginning
    max_sum: Maximum sum subarray
    max_sum_end: Maximum sum of the subarray that must end at the end
    total: Sum of all the elements of the array
    """

    def __init__(self, max_sum_beg, max_sum, max_sum_end, total):
        self.max_sum_beg = max_sum_beg
        self.max_sum = max_sum
        self.max_sum_end = max_sum_end
        self.total = total


class Solution:

    @staticmethod
    def merge_maximum(left_half, right_half):
        """
        Given the Maximum object for left half and the right half of an list
        Create  the Maximum object for the combined list.
        """
        max_sum = max(left_half.max_sum, right_half.max_sum, left_half.max_sum_end + right_half.max_sum_beg)
        max_sum_beg = max(left_half.max_sum_beg, left_half.total + right_half.max_sum_beg)
        max_sum_end = max(right_half.max_sum_end, right_half.total + left_half.max_sum_end)
        total = left_half.total + right_half.total
        return Maximum(max_sum_beg, max_sum, max_sum_end, total)

    def divide_and_conquer(self, nums, i, j):
        """
        Return a Maximum object for the subarray nums [i, j] i and j included
        """
        if i == j:
            return Maximum(nums[i], nums[i], nums[i], nums[i])
        else:
            mid = i + (j - i) // 2  # Split into two parts left and right
            maximum_left = self.divide_and_conquer(nums, i, mid)
            maximum_right = self.divide_and_conquer(nums, mid + 1, j)
            return Solution.merge_maximum(maximum_left, maximum_right)

    def maxSubArray(self, nums: List[int]) -> int:
        return self.divide_and_conquer(nums, 0, len(nums) - 1).max_sum
```

