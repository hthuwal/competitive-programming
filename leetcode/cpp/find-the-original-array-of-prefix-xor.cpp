/* -- https://leetcode.com/problems/find-the-original-array-of-prefix-xor/ -- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // pref[i] = pref[i-1] ^ arr[i]
    // pref[i] ^ pref[i-1] = pref[i-1] ^ arr[i] ^ pref[i-1]
    // pref[i] ^ pref[i-1] = arr[i];
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size(), 0);
        arr[0] = pref[0];
        for (int i = 1; i < pref.size(); i++) {
            arr[i] = pref[i] ^ pref[i - 1];
        }
        return std::move(arr);
    }
};