/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int nCount = 0;
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, 0));
        for (int i = 1; i <= text1.length(); i++)
        {
            for (int j = 1; j <= text2.length(); j++)
            {
                if (text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                nCount = nCount>dp[i][j]? nCount:dp[i][j];
            }            
        }        
        return nCount;
    }
};
// @lc code=end

