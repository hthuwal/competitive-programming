/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/search-a-2d-matrix              */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Just flatten matrix and binary search
 **/
class Solution {
   public:
    int getElement(vector<vector<int>>& matrix, int i) {
        int ri = i / matrix[0].size();
        int rj = i % matrix[0].size();
        return matrix[ri][rj];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = 0;
        int end = (matrix.size() * (matrix[0].size())) - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int ele = getElement(matrix, mid);

            if (ele == target) {
                return true;
            } else if (ele < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};