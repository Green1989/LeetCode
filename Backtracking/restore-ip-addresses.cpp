/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> vecResult;
    vector<string> vecPack;
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12)
        {
            return vecResult;
        }
        backtracking(s, 0);
        return vecResult;        
    }
    void backtracking(string s, int start)
    {
        if (vecPack.size() >= 4)
        {
            if (start == s.length())
            {
                string strTarget = "";
                for (int i = 0; i < vecPack.size(); i++)
                {
                    strTarget += vecPack[i];
                    if (i != vecPack.size() - 1)
                    {
                        strTarget += ".";
                    }
                }
                vecResult.push_back(strTarget);                
            }
            return ;
        }
        if (start >= s.length())
        {
            return;
        }
        for (int len = 1; len <= 3; len++)
        {
            int remainAddBitCount = 4-(vecPack.size()+1);
            int remainStrLen = s.length() - (start + len );
            if (remainStrLen > remainAddBitCount*3)
            {
                continue;
            }
            string str = s.substr(start, len);
            if (isValidAddress(str))
            {
                vecPack.push_back(str);
                backtracking(s, start+len);
                vecPack.pop_back();
            }
        } 
    }
    bool isValidAddress(string s)
    {
        if (s.empty())
        {
            return false;
        }
        if (s[0] == '0' && s.length() > 1)
        {
            return false;
        }
        int n = atoi(s.c_str());
        if (n<0 || n>255)
        {
            return false;
        }
        return true;
    }
};

// int main()
// {
//     Solution sol;
//     string s = "25525511135";
//     vector<string> vecResult;
//     vecResult = sol.restoreIpAddresses(s);

//     for (int i = 0; i < vecResult.size(); i++)
//     {
//         cout << vecResult[i] << ", ";
//         //cout << endl;        
//     }
// 	_getch();
// 	return 0;
// }

// @lc code=end

