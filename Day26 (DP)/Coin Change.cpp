// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1

class Solution {
public:
    int solve(vector<int>& coins, int amount){
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i<= amount; i++){
            for(int num: coins){
                if(i-num >= 0 && dp[i-num] != INT_MAX){
                    dp[i] = min(dp[i-num] + 1, dp[i]);
                }
            }
        }
        if(dp[amount] == INT_MAX)
            return -1;
        else
            return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        return solve(coins, amount);
    }
};
