## partition-labels

[Link to Problem](https://leetcode.com/problems/partition-labels/)

## Solution

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

## Solution v2

#### Python Solution

- Took 40ms and 13.7 MB

```python
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        last_oc = {}
        for i in range(len(S)):
            last_oc[S[i]] = i
        ans = []
        beg, last = 0, 0
        for i in range(len(S)):
            if i > last:
                ans.append(last - beg + 1)
                beg = i
            if last_oc[S[i]] > last:
                last = last_oc[S[i]]
        ans.append(len(S) - beg)
        return ans
```

#### C++ Solution

- Took 12ms and 6.7 MB

```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> last_oc;
        for(int i=0; i<S.length(); i++){
            last_oc[S[i]] = i;
        }
        
        int beg = 0;
        int last = 0;
        vector<int> ans;
        for(int i=0; i<S.length(); i++){
            if (i>last) {
                ans.push_back(last - beg + 1);
                beg = i;
            }
            if (last_oc[S[i]] > last)
                last = last_oc[S[i]];
        }
        ans.push_back(S.length() - beg);
        return ans;
    }
};
```

#### Go Solution

- Took 0ms 🤷‍♂️ and 2.2 MB

```go
func partitionLabels(S string) []int {
    lastOccurrence := map[byte]int{}
    for i, _ := range S {
        lastOccurrence[S[i]] = i
    }
    ans := []int{}
    last, beg := 0, 0
    for i := 0; i < len(S); i++ {
        if (i > last) {
            ans = append(ans, last - beg + 1)
            beg = i;
        }
        if lastOccurrence[S[i]] > last {
            last = lastOccurrence[S[i]]
        }
    }
    ans = append(ans, len(S) - beg)
    return ans
}
```

