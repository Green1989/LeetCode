/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> vecDP(n+1);
        vecDP[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i - 1; j++)
            {
                vecDP[i] = max(vecDP[i], max((i-j)*j, vecDP[i-j]*j));
            }
        }
        return vecDP[n];        
    }
};
// @lc code=end

