/* - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/ - */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isPossible(vector<int>& weights, int days, int capacity) {
        int weight_so_far = 0;
        int num_days = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > capacity) {
                return false;
            }

            if (weight_so_far + weights[i] <= capacity) {
                weight_so_far += weights[i];
            } else {
                num_days++;
                weight_so_far = weights[i];
            }
        }
        if (weight_so_far > 0) {
            num_days++;
        }
        return num_days <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1;
        int h = 5 * 10000 * 500;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (isPossible(weights, days, mid)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return h + 1;
    }
};