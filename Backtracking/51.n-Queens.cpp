/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> vecResult;
    vector<string> vecPack;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> vecQueens(n, vector<bool>(n, false));
        backtracking(n, 0, vecQueens);
        return vecResult;   
    }
    void backtracking(int n, int cur, vector<vector<bool>> vecQueens)
    {
        if (vecPack.size() == n)
        {
            vecResult.push_back(vecPack);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isAllowIndex(n, cur, i, vecQueens))
            {
                vecQueens[cur][i] = true;
                vecPack.push_back(getQueensLine(n, i));
                backtracking(n, cur+1, vecQueens);
                vecQueens[cur][i] = false;
                vecPack.pop_back();
            }
        }
    }
    string getQueensLine(int n, int index)
    {
        string str(n, '.');
        str = str.replace(index, 1, "Q");
        return str;
    }
    bool isAllowIndex(int n, int curLine, int curIndex, vector<vector<bool>> vecQueens)
    {
        for (int row = 0; row < curLine; row++)
        {
            if (vecQueens[row][curIndex])
            {
                return false;
            }            
        }
        for (int row = curLine - 1, column = curIndex - 1; row >= 0 && column >= 0; row--, column--)
        {
            if (vecQueens[row][column])
            {
                return false;
            }
        }
        for (int row = curLine - 1, column = curIndex + 1; row >= 0 && column < n; row--, column++)
        {
            if (vecQueens[row][column])
            {
                return false;
            }            
        }
        // for (int row = 0; row < curLine; row++)
        // {
        //     for (int column = 0; column < n; column++)
        //     {
        //         if (vecQueens[row][column])
        //         {
        //             if (curIndex == column)
        //             {
        //                 return false;
        //             }
        //             if (curIndex == column - (curLine - row) || curIndex == column + curLine - row)
        //             {
        //                 return false;
        //             }                    
        //         }                
        //     }            
        // }
        return true;
    }
};
// int main()
// {
//     Solution sol;
//     vector<vector<string>> vecResult;
// 	int n = 9;
//     vecResult = sol.solveNQueens(n);

//     for (int i = 0; i < vecResult.size(); i++)
//     {
//         for (int j = 0; j < vecResult[i].size(); j++)
//         {
//             cout << vecResult[i][j] << endl;
//         }
//         cout << endl << endl << endl;        
//     }
// 	_getch();
// 	return 0;
// }

// @lc code=end

