/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string curWord = s.substr(j, i-j);
                if (word.find(curWord) != word.end() && dp[j])
                {
                    dp[i] = true;
                }
            }            
        }
        return dp[s.size()];        
    }
};
// @lc code=end

