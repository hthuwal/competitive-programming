### [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/)

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.

---

#### Solution. Time: O(n), Space: O(n)
- Auxillary array Left:
    + Left[i] = true if min(nums[0:i-1]) < nums[i]
    + O(n) space. Creation time: O(n)
- Auxillary array Right:
    + Right[i] = true if max(nums[i+1:n-1]) > nums[i]
    + O(n) space. Creation time: O(n)
- Retrun true if there exist an i s.t both left[i] and right[i] are true.


```c++
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return false;
        vector<bool> left(n, false);
        vector<bool> right(n, false);
        
        int min_so_far = nums[0];
        for(int i=1;i<n;i++)
        {
            if(min_so_far < nums[i])
                left[i] = true;
            else if(nums[i] < min_so_far)
                min_so_far = nums[i];
        }
        
        int max_so_far = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(max_so_far > nums[i])
                right[i] = true;
            else if(nums[i] > max_so_far)
                max_so_far = nums[i];
        }
        
        for(int i=0;i<n;i++)
            if(left[i] and right[i])
                return true;
        return false;
    }
};
```

**Can this be done in O(1) space?**