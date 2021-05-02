/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> vecDP(amount+1, 0);
        vecDP[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                vecDP[j] += vecDP[j-coins[i]];
            }
        }
        return vecDP[amount];
    }
};
// @lc code=end

