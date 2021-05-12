/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include<stack>
#include<conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> vecMark(s.size(), false);
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if (st.empty())
                {
                    vecMark[i] = false;
                }
                else
                {
                    vecMark[st.top()] = true;
                    vecMark[i] = true;
                    st.pop();
                }                
            }            
        }
        int nResult = 0;
        int nCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (vecMark[i])
            {
                nCount++;
            }
            else
            {
                nResult = max(nResult, nCount);
                nCount = 0;
            }
        }
        nResult = max(nResult, nCount);
        return nResult;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    cout << sol.longestValidParentheses(")()())") << endl;
    _getch();
    return 0;
}
