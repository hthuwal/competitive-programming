#### [3 sum](https://leetcode.com/problems/3sum/)

O(n^2) algorithm.

Input: [-1,0,1,2,-1,-4]

- Runtime (by LeetCode):      
    + Python3: 40 ms
    + C++: 0 ms

---
##### Python3: TLE

```python
# from collections import Counter, defaultdict
class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        # fre = Counter(nums)
        fre = {}
        for each in nums:
            if each not in fre:
                fre[each] = 0
            fre[each] += 1
        # print(fre)
        ans = []
        for num in fre:
            a = num
            for num in fre:
                b = num
                c = -b-a
                if c in fre:
                    cond1 = (a == b and b == c and  fre[a] >= 3)
                    cond2 = (a == b and b != c and fre[a] >= 2)
                    cond3 = (a == c and a != b and fre[a] >= 2)
                    cond4 = (b == c and a != b and fre[b] >= 2)
                    cond5 = (a != b and b != c and a != c)
                    # print(a, b, c)
                    # print(cond1, cond2, cond3, cond4, cond5)
                    if (cond1 or cond2 or cond3 or cond4 or cond5):
                        cand = sorted([a,b,c])
                        cand = tuple(cand)
                        ans.append(cand)

        return list(set(ans))
```

---

##### C++: Accepted

```c++
#define vi vector<int>
#define vvi vector<vi>

#define umii unordered_map<int ,int>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        umii fre;
        set<vector<int>> ans;
        for(auto &each: nums)
        {
            if(fre.find(each) == fre.end())
                fre[each] = 0;
            fre[each] += 1;
        }
        
        for(auto &pr1: fre)
        {
            int a = pr1.first;
            for(auto &pr2: fre)
            {
                int b = pr2.first;
                int c = -a-b;
                if(fre.find(c) != fre.end())
                {
                    bool cond1 = (a == b and b == c and  fre[a] >= 3);
                    bool cond2 = (a == b and b != c and fre[a] >= 2);
                    bool cond3 = (a == c and a != b and fre[a] >= 2);
                    bool cond4 = (b == c and a != b and fre[b] >= 2);
                    bool cond5 = (a != b and b != c and a != c);
                    if (cond1 or cond2 or cond3 or cond4 or cond5)
                    {    
                        vi cand({a,b,c});
                        sort(cand.begin(), cand.end());
                        ans.insert(cand);
                    }
                }
            }
        }

        return vvi(ans.begin(), ans.end());
    }
};
```