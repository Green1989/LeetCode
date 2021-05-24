/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nCount = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    nCount++;
                    traveral(grid, i, j);
                }                
            }            
        }
        return nCount;
    }
    void traveral(vector<vector<char>>& grid, int row, int cloumn)
    {
        if ((row < 0) || (row >= grid.size()) || (cloumn < 0) || (cloumn >= grid[row].size()) || (grid[row][cloumn] == '0'))
        {
            return;
        }
        grid[row][cloumn] = '0';
        traveral(grid, row-1, cloumn);
        traveral(grid, row+1, cloumn);
        traveral(grid, row, cloumn-1);
        traveral(grid, row, cloumn+1);        
    }
};
// @lc code=end

