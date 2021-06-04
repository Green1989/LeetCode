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
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        string cur = "";
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cur.push_back(board[i][j]);
                char temp = board[i][j];
                board[i][j] = '*';
                if (backtracking(board, word, cur, i, j))
                    return true;
                board[i][j] = temp;                    
                cur.pop_back();
            }
        }
        return false;
    }
    bool backtracking(vector<vector<char>>& board, string& word, string& cur, int row, int cloumn)
    {
        if (cur[cur.size()-1] != word[cur.size()-1])
        {
            return false;
        }
        if (cur.size() == word.size())
        {
            return true;
        }
        if (row-1 >= 0)
        {
            row--;
            cur.push_back(board[row][cloumn]);
            char temp = board[row][cloumn];
            board[row][cloumn] = '*';            
            if (backtracking(board, word, cur, row, cloumn))
                return true;
            board[row][cloumn] = temp;
            cur.pop_back();
            row++;
        }
        if (row+1 < board.size())
        {
            row++;
            cur.push_back(board[row][cloumn]);
            char temp = board[row][cloumn];
            board[row][cloumn] = '*';
            if (backtracking(board, word, cur, row, cloumn))
                return true;
            board[row][cloumn] = temp;
            cur.pop_back();
            row--;
        }
        if (cloumn-1 >= 0)
        {
            cloumn--;
            cur.push_back(board[row][cloumn]);
            char temp = board[row][cloumn];
            board[row][cloumn] = '*';
            if (backtracking(board, word, cur, row, cloumn))
                return true;
            board[row][cloumn] = temp;
            cur.pop_back();
            cloumn++;
        }
        if (cloumn+1 < board[0].size())
        {
            cloumn++;
            cur.push_back(board[row][cloumn]);
            char temp = board[row][cloumn];
            board[row][cloumn] = '*';
            if (backtracking(board, word, cur, row, cloumn))
                return true;
            board[row][cloumn] = temp;
            cur.pop_back();
            cloumn--;
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<char>> board = {{'a','a','a','a'},{'a','a','a','a'},{'a','a','a','a'}};
    cout << sol.exist(board, "aaaaaaaaaaaaa") << endl;
    _getch();
    return 0;
}

