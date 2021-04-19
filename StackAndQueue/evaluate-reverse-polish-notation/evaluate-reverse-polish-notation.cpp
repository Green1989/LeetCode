/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <conio.h>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <string> staTokens;
        string strNum1 = "";
        string strNum2 = "";
        int nNum;
        for (auto &&str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                strNum2 = staTokens.top();
                staTokens.pop();
                strNum1 = staTokens.top();
                staTokens.pop();
                if (str == "+")
                {
                    nNum = atoi(strNum1.c_str()) + atoi(strNum2.c_str());
                }
                else if (str == "-")
                {
                    nNum = atoi(strNum1.c_str()) - atoi(strNum2.c_str());
                }
                else if (str == "*")
                {
                    nNum = atoi(strNum1.c_str()) * atoi(strNum2.c_str());
                }
                else
                {
                    nNum = atoi(strNum1.c_str()) / atoi(strNum2.c_str());
                }
                staTokens.push(to_string(nNum));      
            }
            else
            {
                staTokens.push(str);
            }      
        }
        if (staTokens.size() == 1)
        {
            return atoi(staTokens.top().c_str());
        }
        else
        {
            return 0;
        }               
        
    }
};
// int main()
// {
//     Solution sol;
//     vector<string> vecTokens = {"4","13","5","/","+"};
//     int nRet = sol.evalRPN(vecTokens);
//     cout << nRet << endl;
//     _getch();
//     return 0;
// }
// @lc code=end

