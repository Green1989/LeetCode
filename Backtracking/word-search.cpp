/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
//up:0  down:1  left:2  right:3
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vecValidBoard(board.size(), vector<bool>(board[0].size(), true));
        string s = "";
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if (backtracking(board, word, s, i, j, vecValidBoard))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool backtracking(vector<vector<char>>& board, string word, string s, int rows, int columns, vector<vector<bool>>& vecValidBoard)
    {       
        if (s.size() > word.size() || s.back() != word[s.size()-1])
        {
            return false;
        }        
        if(word == s)
        {
            return true;
        }
        if (columns-1 >= 0 && vecValidBoard[rows][columns-1])//up
        {
            s.push_back(board[rows][columns-1]);
            vecValidBoard[rows][columns-1] = false;
            if(backtracking(board, word, s, rows, columns-1, vecValidBoard))
                return true;
            s.pop_back();
            vecValidBoard[rows][columns-1] = true;
        }
        if (columns+1 < board[0].size() && vecValidBoard[rows][columns+1])//down
        {
            s.push_back(board[rows][columns+1]);
            vecValidBoard[rows][columns+1] = false;
            if(backtracking(board, word, s, rows, columns+1, vecValidBoard))
                return true;
            s.pop_back();
            vecValidBoard[rows][columns+1] = true;
        }
        if (rows-1 >= 0 && vecValidBoard[rows-1][columns])//left
        {
            s.push_back(board[rows-1][columns]);
            vecValidBoard[rows-1][columns] = false;
            if(backtracking(board, word, s, rows-1, columns, vecValidBoard))
                return true;
            s.pop_back();
            vecValidBoard[rows-1][columns] = true;
        }
        if (rows+1 < board.size() && vecValidBoard[rows+1][columns])//down
        {
            s.push_back(board[rows+1][columns]);
            vecValidBoard[rows+1][columns] = false;
            if(backtracking(board, word, s, rows+1, columns, vecValidBoard))
                return true;
            s.pop_back();
            vecValidBoard[rows+1][columns] = true;
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEE";
    cout << sol.exist(board, word) << endl;
    _getch();
    return 0;
}