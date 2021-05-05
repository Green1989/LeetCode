/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2));
        dp[0][0] = prices[0] * (-1);//第0天持有股票拥有的现金
        dp[0][1] = 0;//第0天不持有股票拥有的现金 
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        }
        return dp[prices.size()-1][1];        
    }
};
// @lc code=end

