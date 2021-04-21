/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <conio.h>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> vecResult;
    vector<string> vecAlphabet;
    //string strResult;
    vector<string> letterCombinations(string digits) {
        if (digits == "")
        {
            return vecResult;
        }
        
        createAlphabet(); 
        backtracking(digits, 0, "");
        return vecResult;
    }
    void backtracking(string digits, int start, string strResult)
    {
        if (strResult.length() == digits.length())
        {
            vecResult.push_back(strResult);
        }
        for (int i = start; i < digits.length(); i++)
        {
            int index = digits[i] - '2';
            for (int j = 0; j < vecAlphabet[index].size(); j++)
            {
                backtracking(digits, i+1, strResult+vecAlphabet[index][j]);
            }
        }        
    }
    void createAlphabet()
    {
        char c = 'a'-1;
        for (int i = 0; i < 8; i++)
        {
            vecAlphabet.push_back("");
            vecAlphabet[i] += (++c);
            vecAlphabet[i] += (++c);
            vecAlphabet[i] += (++c);
            if (i == 5 || i == 7)
            {
                vecAlphabet[i] += (++c);
            }            
        }
    }
};
// int main()
// {
//     Solution sol;
//     vector<string> vecResult;
// 	vecResult = sol.letterCombinations("23");
// 	for (int i = 0; i < vecResult.size(); i++)
//     {
//         cout << vecResult[i] << ", ";     
//     }

//     cout << endl << "size = " << vecResult.size();
    
// 	_getch();
// 	return 0;
// }
// @lc code=end

