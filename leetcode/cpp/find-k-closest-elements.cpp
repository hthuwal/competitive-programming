// Source: https://leetcode.com/problems/find-k-closest-elements/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int h = arr.size() - 1;

        while (h - l + 1 > k) {
            int a = abs(arr[l] - x);
            int b = abs(arr[h] - x);
            if (a > b) {
                l++;
            } else {
                // either a < b or a == b
                // both distances are equal, we'll discard the bigger number
                // because smaller number is assumed closer
                h--;
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + h + 1);
    }
};