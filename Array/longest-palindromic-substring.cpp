/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include<conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        vector<string> dp(s.size());
        dp[0] = s[0];
        int nLeft, nRight;
        for (int i = 1; i < s.size(); i++)
        {         
            int offset = 0;
            nLeft = i - dp[i-1].size() - 1;
            nRight = i;
            while (nLeft < nRight && nLeft >= 0)
            {
                if(s[nLeft] != s[nRight])
                {
                    break;
                }
                nLeft++;
                nRight--;
            }
            if (nLeft < nRight)
            {
                nLeft = i - dp[i-1].size();
                nRight = i;
                while (nLeft < nRight)
                {
                    if(s[nLeft] != s[nRight])
                    {
                        break;
                    }
                    nLeft++;
                    nRight--;
                }
                if (nLeft >= nRight)
                {
                    offset = 1;
                }
            }
            else
            {
                offset = 2;
            }
            if (offset == 0)
            {
                dp[i] = dp[i-1];
            }
            else if(offset == 1)
            {
                dp[i] = s.substr(i - dp[i-1].size(), dp[i-1].size()+offset);
            }
            else
            {
                dp[i] = s.substr(i - dp[i-1].size()-1, dp[i-1].size()+offset);
            }
        }
        return dp[s.size()-1];
    }
};
// @lc code=end
int main()
{
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl;
    _getch();
    return 0;
}

