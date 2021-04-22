/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <conio.h>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> vecResult;
    vector<string> vecPack;
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return vecResult;
    }
    void backtracking(string s, int start)
    {
        if (start == s.length())
        {
            vecResult.push_back(vecPack);
            return ;
        }
        for (int len = 1; start + len <= s.length(); len++)
        {
            string str = s.substr(start, len);
            if(isPalindrome(str))
            {
                vecPack.push_back(str);
                backtracking(s, start+len);
                vecPack.pop_back();
            }
        }
    }
    bool isPalindrome(string str)
    {
        for (int i = 0; i < str.length()/2; i++)
        {
            if (str[i] != str[str.length()-1-i])
            {
                return false;
            }
        }
        return true;
    }
};
// int main()
// {
//     Solution sol;
//     string s = "a";
//     vector<vector<string>> vecResult;
//     vecResult = sol.partition(s);

//     for (int i = 0; i < vecResult.size(); i++)
//     {
//         for (int j = 0; j < vecResult[i].size(); j++)
//         {
//             cout << vecResult[i][j] << ", ";
//         }
//         cout << endl;        
//     }
// 	_getch();
// 	return 0;
// }

// @lc code=end

