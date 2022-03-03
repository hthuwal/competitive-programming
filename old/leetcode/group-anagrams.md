#### [Group Anagrams](https://leetcode.com/problems/group-anagrams/)
  
Given an array of strings, group anagrams together.

##### C++: 20ms

```c++
#define vs vector<string>
#define umsvs unordered_map<string, vs>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        umsvs dict;
        string key;
        vector<vs> ans;
        for(int i=0;i<strs.size();i++)
        {
            key = strs[i];
            sort(key.begin(), key.end());
            if(dict.find(key) == dict.end())
               dict[key] = vs();
            dict[key].push_back(strs[i]);
        }
        
        for(auto each: dict)
            ans.push_back(each.second);
        return ans;
    }
};
```

---

##### Python3: 128ms

```python
class Solution:
    def groupAnagrams(self, strs):
        ans = {}
        for string in strs:
            key = "".join(sorted(string))
            if key not in ans:
                ans[key] = []
            ans[key].append(string)
        
        return list(ans.values())
```