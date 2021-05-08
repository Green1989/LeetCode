/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

#include <conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        vector<int> dp(s.size(), 1);
        for (int i = 1; i < s.size(); i++)
        {
            dp[i] = dp[i-1] + GetSubstrings(s, 0, i);
        }        
        return dp[s.size()-1];
    }
    int GetSubstrings(string s, int start, int end)
    {
        int nCount = 1;
        for (int i = start; i < end; i++)
        {
            int begin = i;
            int stop = end;
            while (begin < stop && s[begin] == s[stop])
            {
                begin++;
                stop--;
            }
            if (begin >= stop)
            {
                nCount++;
            }
        }
        return nCount;        
    }
};
// @lc code=end
int main()
{
    Solution sol;
	string s = "aaa";
	int nRet = sol.countSubstrings(s);
	cout << nRet << endl;
	_getch();
	return 0;
}
