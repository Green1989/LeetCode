/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> vecDP(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            vecDP[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            vecDP[0][i] = 1;
        }        
        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                vecDP[i][j] = vecDP[i-1][j] + vecDP[i][j-1];
            }            
        }
        return vecDP[m-1][n-1];        
    }
};
// @lc code=end

