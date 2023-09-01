/* -------------------------------------------------------------------------- */
/*         https://leetcode.com/problems/median-of-two-sorted-arrays/         */
/* -------------------------------------------------------------------------- */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged_array(n + m, 0);

        int i = 0, j = 0, k = 0;
        for (; i < n && j < m;) {
            if (nums1[i] < nums2[j]) {
                merged_array[k] = nums1[i];
                i++;
                k++;
            } else {
                merged_array[k] = nums2[j];
                k++;
                j++;
            }
        }

        while (i < n) {
            merged_array[k] = nums1[i];
            k++;
            i++;
        }

        while (j < m) {
            merged_array[k] = nums2[j];
            k++;
            j++;
        }

        if ((n + m) % 2 == 1) {
            return merged_array[(n + m) / 2];
        } else {
            int x = (n + m) / 2;
            return double(merged_array[x - 1] + merged_array[x]) / 2.0;
        }
    }
};

int main() {
    vector<int> a = {1, 3};
    vector<int> b = {2, 4};
    vector<int> c = {2};
    cout << Solution().findMedianSortedArrays(a, b) << "\n";
    cout << Solution().findMedianSortedArrays(a, c);
}