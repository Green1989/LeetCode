/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<int> dp(s.size(), 1);
        for (int i = 1; i < s.size(); i++)
        {
            dp[i] = dp[i-1] + getLongerPalindromeSubseq(s, 0, i, dp[i]);
        }
        return dp[s.size()-1];

    }
    int getLongerPalindromeSubseq(string s, int start, int end, int len)//子函数逻辑有问题
    {        
        int nCurLen = 0;
        int nStop = end;
        for (int i = start; i < end; i++)
        {
            if(s[i] == s[nStop])
            {
                nStop--;
                nCurLen++;
            }
            if(nCurLen + (end - i) <= len)
            {
                return 0;
            }
        }        
        return nCurLen - len;
    }
};
// @lc code=end

