/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int nMaxProfit = 0;
        int nMinPrices = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            nMinPrices = nMinPrices<prices[i] ? nMinPrices:prices[i];
            nMaxProfit = nMaxProfit>(prices[i] - nMinPrices) ? nMaxProfit:(prices[i] - nMinPrices);
        }        
        return nMaxProfit;
    }
};
// @lc code=end

