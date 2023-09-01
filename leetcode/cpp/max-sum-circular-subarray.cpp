/* -------------------------------------------------------------------------- */
/*        https://leetcode.com/problems/maximum-sum-circular-subarray/        */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int calculateMaxIfAllNegative(vector<int>& nums) {
        int maxNum = nums[0];
        for (int& each : nums) {
            if (each >= 0) {
                return 0;
            }
            maxNum = max(maxNum, each);
        }
        return maxNum;
    }

    int calculateMaxPositiveSum(vector<int>& nums) {
        int maxSumTillNow = nums[0];
        int overAllMaxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxSumTillNow = max(maxSumTillNow + nums[i], nums[i]);
            if (overAllMaxSum < maxSumTillNow) {
                overAllMaxSum = maxSumTillNow;
            }
        }
        return overAllMaxSum;
    }

    int calculateMinNegativeSum(vector<int>& nums) {
        int minSumTillNow = nums[0];
        int overAllMinSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            minSumTillNow = min(minSumTillNow + nums[i], nums[i]);

            if (minSumTillNow < overAllMinSum) {
                overAllMinSum = minSumTillNow;
            }
        }
        return overAllMinSum;
    }

    int calculateTotalSum(vector<int>& nums) {
        int sum = 0;
        for (int& each : nums) {
            sum += each;
        }
        return sum;
    }

    /**
     * Edge Cases:
     * 1. If it is all negative. Find the max element or least negative elements.
     * 2. Calculate Usual Max Sum Subarray.
     * 3. For the circular part if the max is wrap around: totalSum - Calculate Usual Min Negative Sum Subarray
     **/
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxNumIfAllNegative = calculateMaxIfAllNegative(nums);
        if (maxNumIfAllNegative != 0) {  // It is all negative
            return maxNumIfAllNegative;
        }
        int maxPositiveSum = calculateMaxPositiveSum(nums);
        int minNegativeSum = calculateMinNegativeSum(nums);
        int totalSum = calculateTotalSum(nums);
        return max(maxPositiveSum, totalSum - minNegativeSum);
    }
};

void print(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << ": ";
}

int main() {
    vector<int> nums({1, -2, 3, -2});
    print(nums);
    cout << Solution().maxSubarraySumCircular(nums) << "\n";

    nums = {5, -3, 5};
    print(nums);
    cout << Solution().maxSubarraySumCircular(nums) << "\n";

    nums = {-3, -2, -3};
    print(nums);
    cout << Solution().maxSubarraySumCircular(nums) << "\n";

    nums = {-2, 4, -5, 4, -5, 9, 4};
    print(nums);
    cout << Solution().maxSubarraySumCircular(nums) << "\n";
}