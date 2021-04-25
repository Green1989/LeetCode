/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0);
    }
    bool backtracking(vector<vector<char>>& board, int row)
    {
        if (row == 9)
        {
            return true;
        }
        for (int column = 0; column < 9; column++)
        {
            if (board[row][column] == '.')
            {
                bool bNumsUsed[9] = {false};
                if (getSuitableNumber(board, row, column, bNumsUsed) > 0)
                {
                    for (int num = 0; num < 9; num++)
                    {
                        if (bNumsUsed[num] == false)
                        {
                            board[row][column] = '1' + num;
                            if(backtracking(board, row+1))
                            {
                                break;
                            }
                            else
                            {
                                board[row][column] = '.';
                            }
                        }                        
                    }
                    if (board[row][column] == '.')
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    int getSuitableNumber(vector<vector<char>>& board, int row, int column, bool* bNumsUsed)
    {
        //bool bNumsUsed[9] = {false};
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] != '.')
            {
                bNumsUsed[board[row][i] - '1'] = true;
            }
            if (board[i][column] != '.')
            {
               bNumsUsed[board[i][column] - '1'] = true;
            }                        
        }
        for (int i = (row/3) * 3; i < 3; i++)
        {
            for (int j = (column/3) * 3; j < 3; j++)
            {
                if (board[i][j] != '.')
                {
                    bNumsUsed[board[i][j] - '1'] = true;
                }
            }            
        }
        int nCount = 0;
        for (int i = 0; i < 9; i++)
        {
            if (bNumsUsed[i] == false)
            {
                nCount++;
            }            
        }
        return nCount;
    }
};
int main()
{
    Solution sol;
    vector<vector<char>> vecResult = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    sol.solveSudoku(vecResult);

    for (int i = 0; i < vecResult.size(); i++)
    {
        for (int j = 0; j < vecResult[i].size(); j++)
        {
            cout << vecResult[i][j] << ", ";
        }
        cout << endl << endl << endl;        
    }
	_getch();
	return 0;
}

// @lc code=end

