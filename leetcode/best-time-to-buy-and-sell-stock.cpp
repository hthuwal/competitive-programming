#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /* ----- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee ---- */
    // O(n) space, O(n) time
    int maxProfitWithTransactionFee(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> tryToBuy(n + 2, 0);
        vector<int> doNotBuy(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            tryToBuy[i] = max(-prices[i] + doNotBuy[i + 1], tryToBuy[i + 1]);
            doNotBuy[i] = max(prices[i] - fee + tryToBuy[i + 1], doNotBuy[i + 1]);
        }
        return tryToBuy[0];
    }

    // O(1) space, O(n) time
    int maxProfitWithTransactionFee_SpaceOptimized(vector<int>& prices, int fee) {
        int n = prices.size();

        int tryToBuyTom = 0;
        int doNotBuyTom = 0;

        for (int i = n - 1; i >= 0; i--) {
            int tryToBuyToday = max(-prices[i] + doNotBuyTom, tryToBuyTom);
            int doNotBuyToday = max(prices[i] - fee + tryToBuyTom, doNotBuyTom);

            tryToBuyTom = tryToBuyToday;
            doNotBuyTom = doNotBuyToday;
        }
        return tryToBuyTom;
    }

    /* ---- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown ---- */
    // O(n) space, O(n) time
    int maxProfitWithCoolDown(vector<int>& prices) {
        int n = prices.size();

        vector<int> canBuy(n + 2, 0);
        vector<int> cannotBuy(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            canBuy[i] = max(-prices[i] + cannotBuy[i + 1], canBuy[i + 1]);
            cannotBuy[i] = max(prices[i] + canBuy[i + 2], cannotBuy[i + 1]);
        }
        return canBuy[0];
    }

    // O(1) space, O(n) time
    int maxProfitWithCoolDown_SpaceOptimized(vector<int>& prices) {
        int n = prices.size();

        int canBuyTom = 0;
        int canBuyDayAfterTom = 0;
        int cannotBuyTom = 0;

        for (int i = n - 1; i >= 0; i--) {
            int canBuyToday = max(-prices[i] + cannotBuyTom, canBuyTom);
            int cannotBuyToday = max(prices[i] + canBuyDayAfterTom, cannotBuyTom);

            canBuyDayAfterTom = canBuyTom;
            canBuyTom = canBuyToday;
            cannotBuyTom = cannotBuyToday;
        }
        return canBuyTom;
    }

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