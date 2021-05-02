/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 10001);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j >= coins[i])
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }            
        }
        if (dp[amount] > 10000)
        {
            return -1;
        }        
        return dp[amount];
    }
};
// @lc code=end

