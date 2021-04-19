/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <conio.h>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string removeDuplicates(string S) {
        string sResult;
        stack <char> staStr;
        for (auto &&c : S)
        {
            if (staStr.empty())
            {
                staStr.push(c);
            }
            else if (staStr.top() == c)
            {
                staStr.pop();
            }
            else
            {
                staStr.push(c);
            }
        }
        int nIndex = staStr.size()-1;
        sResult.resize(nIndex+1);
        while (!staStr.empty())
        {
            sResult[nIndex] = staStr.top();
            cout << "sResult[" << nIndex << "]=" << sResult[nIndex] << endl;
            staStr.pop();
            nIndex--;
        }
        return sResult;  
    }
};
// @lc code=end

