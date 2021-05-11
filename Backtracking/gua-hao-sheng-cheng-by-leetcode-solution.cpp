/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include<conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> vecResult;
    vector<string> generateParenthesis(int n) {
        string s = "";        
        backtracking(s, 2*n);
        return vecResult;
    }
    void backtracking(string s, int len)
    {
        int nBalance = valid(s, len);
        if (nBalance < 0)
        {
            return;
        }        
        if (s.size() == len)
        {
            if (nBalance == 0)
            {            
                vecResult.push_back(s);                
            }
            return ;
        }
        backtracking(s+"(", len);
        backtracking(s+")", len);
    }
    int valid(const string& str, int len)
    {
        int nBalance = 0;
        for (auto &&c : str)
        {
            if (c == '(')
            {
                nBalance++;
            }
            else
            {
                nBalance--;
            }    
            if (nBalance < 0 || nBalance*2 > len)
            {
                return -1;
            }
        }
        return nBalance;        
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<string> vecRes = sol.generateParenthesis(3);
    for (auto &&s : vecRes)
    {
        cout << s << endl;
    }
    
    _getch();
    return 0;
}
