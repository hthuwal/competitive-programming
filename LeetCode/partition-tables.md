## partition-labels

[Link to Problem](https://leetcode.com/problems/partition-labels/)

# Solution

```python
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        last_index_of_char = {}
        for (i, ch) in enumerate(S):
            if ch not in last_index_of_char:
                last_index_of_char[ch] = i
            last_index_of_char[ch] = max(last_index_of_char[ch], i)

        ans = []
        start = 0
        while (start < len(S)):
            ch = S[start]
            # You'll atleast have to take substring upto the last occurrence of first character.
            end = last_index_of_char[ch]
            j = start
            while(j <= end):
                char = S[j]
                # Update the end of the substring with the last occurrence of the current character
                # if its last occurrence is beyond already decided end.
                end = max(end, last_index_of_char[char])
                j += 1
            ans.append(end - start + 1)
            # Next substtring would start from end + 1
            start = end + 1

        return ans
```
