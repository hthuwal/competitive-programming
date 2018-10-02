### [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

Given a non-empty array of integers, return the k most frequent elements.

#### Solution: O(n+k)

- Store the freq of eac element in a map/dict(`count`). O(n)
- Find maximum_freq. O(n)
- Create an list (`freq`) of size maximum_freq+1.
    + Each element is a list
- Append each n to freq[counts[n]] O(n)
- Start from the back of the freq list and print k numbers. O(k)

**Python3 Code**
```python
from collections import Counter
class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        nums = Counter(nums)
        max_freq = max(list(nums.values()))
        freq = [[] for i in range(max_freq+1)]
        ans = []
        
        for key in nums:
            freq[nums[key]].append(key)
            
        
        i = len(freq)-1
        K = k
        while(k>0 and i>=0):
            if(freq[i]):                
                ans.extend(list(freq[i]))
                k -= (len(freq[i]))
            i -= 1
        
        return ans[0:K]
```
