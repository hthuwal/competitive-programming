#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /* ----- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ ----- */
    // Buy once and sell once later
    int maxProfitSinglePurchase(vector<int>& prices) {
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

    /* ---- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii ---- */
    // Buy and sell as many times as you want
    // Consider the scenario: a b c d -> a<b<c<d
    // b-a + c-b + d -c => d-a
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = 1;
        int profit = 0;
        while (j < prices.size()) {
            if (prices[j] > prices[i]) {
                profit += (prices[j] - prices[i]);
            }
            i++;
            j++;
        }
        return profit;
    }
};