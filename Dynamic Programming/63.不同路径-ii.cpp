/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> vecDP(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0)
            {
                vecDP[i][0] = 1;
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 0)
            {
                vecDP[0][i] = 1;
            }
            else
            {
                break;
            }
        }   
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    vecDP[i][j] = vecDP[i-1][j] + vecDP[i][j-1];
                }
                else
                {
                    vecDP[i][j] = 0;
                }
            }
        }
        return vecDP[m-1][n-1];    
    }
};
// @lc code=end

