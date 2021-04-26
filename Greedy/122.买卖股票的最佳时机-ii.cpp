/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
        {
            return 0;
        }        
        int nBuyIndex = -1;
        int nMaxProfits = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] < prices[i+1])
            {
                if (nBuyIndex < 0)
                {
                    nBuyIndex = i;
                }                
            }
            else if (nBuyIndex >= 0 && prices[i] > prices[i+1])
            {
                nMaxProfits += (prices[i] - prices[nBuyIndex]);
                nBuyIndex = -1;
            }
        }
        if (nBuyIndex >= 0)
        {
            nMaxProfits += (prices[prices.size() - 1] - prices[nBuyIndex]);
        }        
        return nMaxProfits;        
    }
};
// @lc code=end

