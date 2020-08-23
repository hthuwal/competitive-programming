### Problem

[Next Greater Element 2](https://leetcode.com/problems/next-greater-element-ii/)

### O(n) stack based solution.

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> stack; // Numbers for which nextGreaterElements has not been found yet.
    vector<int> answers(nums.size(), -1);
    for(int i=0; i<nums.size()*2; i++) {
        if(stack.empty()) {
            if (i >= nums.size())
                break;
            stack.push(i);
        }
        else {
            while(!stack.empty() && nums[stack.top()] < nums[i % nums.size()]) {
                answers[stack.top()] = nums[i % nums.size()];
                stack.pop();
            }
            if (i < nums.size()) {
                stack.push(i);
            }
        }
    }
    return answers;
};
```

### O(n^2) brute force

- Accepted but 10 times slower than O(n)

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> answers(nums.size(), -1);
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<i+nums.size(); j++) {
                if(nums[i] < nums[j % nums.size()]) {
                    answers[i] = nums[j % nums.size()];
                    break;
                }
            }
        }
        return answers;
    }
};
```
