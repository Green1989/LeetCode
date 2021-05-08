/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())
        {
            return 0;
        }
        
        vector<vector<unsigned int>> dp(s.size()+1, vector<unsigned int>(t.size()+1));
        for (int i = 0; i <= s.size(); i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= t.size(); j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= t.size(); j++)
            {
                if (s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
// @lc code=end

