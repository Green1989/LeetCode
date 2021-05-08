/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0 || word2.size() == 0)
        {
            return word1.size() + word2.size();
        }        
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return word1.size() + word2.size() - dp[word1.size()][word2.size()] - dp[word1.size()][word2.size()];
    }
};
// @lc code=end

