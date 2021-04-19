/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <stack>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> staStr;
        for (auto &&c : s)
        {
            if (c == ')')
            {
                if(staStr.empty() || staStr.top() != '(')
                    return false;
                staStr.pop();
            }
            else if (c == '}')
            {
                if(staStr.empty() || staStr.top() != '{')
                    return false;
                staStr.pop();
            }
            else if (c == ']')
            {
                if(staStr.empty() || staStr.top() != '[')
                    return false;
                staStr.pop();
            }
            else
            {
                staStr.push(c);
            }
        }
        return staStr.empty();                
    }
};
// @lc code=end

