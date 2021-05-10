/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++)
        {
            if (p[i] == '*' && i-2 >= 0)
            {
                dp[0][i] = dp[0][i-2];
            }            
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i-1] == p[j-1] || p[j-1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*')
                {
                    if (dp[i][j-2])
                    {
                        dp[i][j] = true;
                    }
                    else if (s[i-1] == p[j-1-1] || p[j-1-1] == '.')
                    {
                        dp[i][j] = dp[i-1][j];
                    }               
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                else
                {
                    dp[i][j] = false;
                }
            }            
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end

