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
        backtracking(board);
    }
    bool backtracking(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = '1'; k <= '9'; k++)
                    {
                        if (isvalid(board, i, j, k))
                        {
                            board[i][j] = k;
                            if (backtracking(board))
                            {
                                return true;
                            }
                            board[i][j] = '.';          
                        }
                    }
                    return false;
                }
            }            
        }
        return true;
    }
    bool isvalid(vector<vector<char>>& board, int row, int column, char val)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (val == board[row][i])
            {
                return false;
            }            
        }
        for (size_t i = 0; i < board[row].size(); i++)
        {
            if (val == board[i][column])
            {
                return false;
            }            
        }
        int rowStart = row/3 *3;
        int columnStart = column/3 *3;
        for (int i = rowStart; i < rowStart+3; i++)
        {
            for (int j = columnStart; j < columnStart+3; j++)
            {
                if (val == board[i][j])
                {
                    return false;
                }
            }
        }
        return true;
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

