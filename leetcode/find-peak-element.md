### [Find Peak Element](https://leetcode.com/problems/find-peak-element/)

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

#### Solution: O(n)

Traverse the list and check each element.

```c++
class Solution {
public:
    int findPeakElement(vector<int>& a) {
        long long int next, prev;
        for(int i=0; i<a.size(); i++)
        {
            if(i==0)
                prev = LONG_MIN;
            else
                prev = a[i-1];
            
            if(i == a.size()-1)
                next = LONG_MIN;
            else
                next = a[i+1];
            
            if(a[i]>prev and a[i] > next)
                return i;
            
        }
        return -1;
    }
    
};
```

#### Solution O(log n): Binary Search Like approach

- If mid is greater than it's neighbors return it
- else if mid is smaller than it's left neighbour, peak must be in left half
- else mid iis smaller than it's right neighbour, peak must be in right half

```c++
#define vi vector<int>
class Solution {
public:
    int peak(vi &a, int l, int r)
    {
        if(l<=r)
        {
            int mid = l+(r-l)/2;
            
            long long int prev, next;
            prev = mid == 0 ? LONG_MIN : a[mid-1];
            next = mid == a.size()-1 ? LONG_MIN : a[mid+1];
            
            if(a[mid]>prev and a[mid] > next)
                return mid;
            else if(prev > a[mid])
                return peak(a, l, mid-1);
            else 
                return peak(a, mid+1, r);
        }
        return -1;
    }
    int findPeakElement(vector<int>& a) {
        return peak(a, 0, a.size()-1);
    }
    
};
```