/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        int nCoinsSize = sqrt(n);
        vector<int> dp(n+1, 10001);
        dp[0] = 0;
        for (int i = 1; i <= nCoinsSize; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j >= i*i)
                {
                    dp[j] = min(dp[j], dp[j - i*i] + 1);
                }
            }            
        }
        if (dp[n] > 10000)
        {
            return -1;
        }        
        return dp[n];
    }
};
// @lc code=end

