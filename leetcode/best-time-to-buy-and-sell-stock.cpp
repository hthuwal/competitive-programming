/* -------------------------------------------------------------------------- */
/*       https://leetcode.com/problems/best-time-to-buy-and-sell-stock/       */
/* -------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int minSofar = prices[0];
        int maxProfit = 0;
        int currentProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            currentProfit = prices[i] - minSofar;
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
            minSofar = min(minSofar, prices[i]);
        }
        return maxProfit;
    }
};