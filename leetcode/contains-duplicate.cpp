/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/contains-duplicate              */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {        
        // 1 liner
        return unordered_set<int>(nums.begin(), nums.end()).size() != nums.size();
    }
};