/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(t.length()+1, vector<int>(s.length()+1));
        for (int i = 1; i <= t.length(); i++)
        {
            for (int j = 1; j <= s.length(); j++)
            {
                if (t[i-1] == s[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[t.length()][s.length()] == s.length();
   
    }
};
// @lc code=end

