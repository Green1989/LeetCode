/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include <conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() < 2)
        {
            return 0;
        }
        int start = 0;
        int end = -1;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (end < 0)
            {
                if (prices[i] - prices[start] > fee)
                {
                    end = i;
                }
                else if (prices[i] < prices[start])
                {
                    start = i;
                }                
            }
            else
            {
                if (prices[i] - prices[end] > 0)
                {
                    end = i;
                }
                if (prices[end] - prices[i] > fee)
                {
                    profit += (prices[end] - prices[start] - fee);
                    start = i;
                    end = -1;
                }
            }
        }
        if (end > 0)
        {
            profit += (prices[end] - prices[start] - fee);
        }        
        return profit;
    }
};
// int main()
// {
//     Solution sol;
//     vector<int> vecResult = {1,3,7,5,10,3};
//     int fee = 3;
//     int nRet = sol.maxProfit(vecResult, fee);
//     cout << nRet << endl;
    
// 	_getch();
// 	return 0;
// }
// @lc code=end

