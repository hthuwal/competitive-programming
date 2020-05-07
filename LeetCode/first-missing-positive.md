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
