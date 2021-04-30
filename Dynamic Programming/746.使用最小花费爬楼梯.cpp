/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int nSize = cost.size();
        int nDP[nSize];
        nDP[0] = cost[0];
        nDP[1] = cost[1];
        for (int i = 2; i < nSize; i++)
        {
            nDP[i] = min(nDP[i-1], nDP[i-2]) + cost[i];
        }
        return min(nDP[nSize-1], nDP[nSize-2]);
    }
};
// @lc code=end

