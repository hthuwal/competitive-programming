#### [Merge Intervals](https://leetcode.com/problems/merge-intervals/)

Given a collection of intervals, merge all overlapping intervals.

#### Solution

```python
# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals.sort(key=lambda x: x.start)
        n = len(intervals)
        ans = []
        
        i = 0
        while(i<n):
            end = intervals[i].end
        
            j = i+1
            while(j < n and intervals[j].start <= end):
                end = max(intervals[j].end, end)
                j += 1
            i = j
            ans.append(Interval(intervals[i].start, end))
        
        return ans
            
```