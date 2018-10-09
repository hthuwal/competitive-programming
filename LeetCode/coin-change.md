#### [Coin Change](https://leetcode.com/problems/coin-change/)

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int num_coins[amount+1];
        num_coins[0]=0;
        for(int i=1;i<=amount;i++)
        {
            num_coins[i]=INT_MAX;            
            for(auto coin: coins)
            {
                if(coin<=i)
                {
                    if(num_coins[i-coin]!=INT_MAX and num_coins[i] > 1+num_coins[i-coin])
                        num_coins[i] = 1 + num_coins[i-coin];
                }
            }
        }
        
        return num_coins[amount] == INT_MAX ? -1 : num_coins[amount];
    }
};
```