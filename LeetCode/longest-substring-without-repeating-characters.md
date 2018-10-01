### [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters)

Given a string, find the length of the longest substring without repeating characters.

### Python3 

- Set the beginning of max_len string to 0. 
- Keep track of last index of each of the letters as you encounter them. 
- As soon as you encounter a letter with last_index >= beg. Reset beginning to the old_occurence of the letter  + 1.

```python
from collections import defaultdict
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        last_index = defaultdict(lambda : -1)
        beg = 0
        max_len = 0
        for i in range(len(s)):
            l = s[i]
            if last_index[l] < beg:
                last_index[l] = i
            else:
                beg = last_index[l] + 1
                last_index[l] = i;
            
            if(i - beg + 1 > max_len):
                max_len = i - beg + 1
            # print(s[beg], s[i], max_len, repr(last_index))
        return max_len
```
