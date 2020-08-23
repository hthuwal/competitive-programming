### [Search for a Range](https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/802)

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

#### Solution O(log n)

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lb == nums.size() or nums[lb] != target)
            return vector<int>({-1,-1});
        else
            return vector<int>({lb, ub-1});
            
    }
};
```

#### TODO: Implement lower_bound and upper_bound yourself