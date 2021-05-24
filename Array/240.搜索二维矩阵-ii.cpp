/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int clumn = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == target)
            {
                return true;
            }
            else if (matrix[i][0] > target)
            {
                break;
            }
            row = i;
        }
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == target)
            {
                return true;
            }
            else if (matrix[0][j] > target)
            {
                break;
            }
            clumn = j;
        }
        for (int i = 1; i <= row; i++)
        {
            if (matrix[i][clumn] == target)
            {
                return true;
            }
            else if (matrix[i][clumn] > target)
            {
                break;
            }
        }
        for (int j = 1; j <= clumn; j++)
        {
            if (matrix[row][j] == target)
            {
                return true;
            }
            else if (matrix[row][j] > target)
            {
                break;
            }
        }
        return false;
    }
};
// @lc code=end

