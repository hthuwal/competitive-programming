## [Search a Range](https://www.interviewbit.com/problems/search-for-a-range/)

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

---

### Using Library Functions O(log n)
```cpp
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    auto left = lower_bound(begin(A), end(A), B);
    auto right = upper_bound(begin(A), end(A), B);
    if(*left != B)
        return vector<int> ({-1, -1});
    return vector<int> ( {left-begin(A), right-begin(A)-1});

}
```

Similar code can be written in python using `bisect_left` and `bisect_right`. 

---

### Implementing the required Functions O(log n)

```python
class Solution:
    def blmo(self, a, l, r, num):
        """
        blmo: binary search the left most occurrence
        Return the index of the left most occurrence of num in a[l..r]
        
        Return -1 if not found
        """
        while l<=r:
            mid = (l+r)/2
            if a[mid] == num: ## if this the number still keep looking in the left
                r = mid-1
            elif a[mid] < num:
                l = mid +1
            else:
                r = mid-1
        
        r = r + 1
        return -1 if a[r] != num else r
        
    def brmo(self, a, l, r, num):
        """
        brmo: binary search the right most occurrence
        Return the index of the right most occurrence of num in a[l..r]
        
        Return -1 if not found.
        """
        while l<=r:
            mid = (l+r)/2
            if a[mid] == num: ## if this the number still keep looking in the right
                l = mid+1
            elif a[mid] < num:
                l = mid+1
            else:
                r = mid-1
        
        l = l-1
        return -1 if a[l] != num else l  

    def searchRange(self, a, num):
        lb = self.blmo(a, 0, len(a)-1, num)
        ub = self.brmo(a, 0, len(a)-1, num)
        return (lb, ub)
```