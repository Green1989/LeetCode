/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<vector<int>>> dp(matrix.size(), vector<vector<int>>(matrix[0].size(), vector<int>(2)));
        int index = -1;
        for (int i = 0; i < dp.size(); i++)
        {
            if (matrix[0][i] == '0')
            {
                index = i;
            }
            dp[0][i] = {0, index+1};
        }
        index = -1;
        for (int i = 0; i < dp[0].size(); i++)
        {
            if (matrix[i][0] == '0')
            {
                index = i;
            }
            dp[0][i] = {index+1, 0};           
        }
        for (int i = 0; i < dp.size(); i++)
        {         
            for (int j = 0; j < dp[i].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    bool bRows = true;
                    bool bCloumns = true;             
                    int nRows = 0;
                    int nCloumns = 0;          
                    //dp[i-1]][j]
                    for(int k = j-1; k >= dp[i-1][j][1] && bRows; k--)
                    {
                        if (matrix[i][k] == '0')
                        {
                            bRows = false;
                            nCloumns = k;
                        }
                    }
                    //dp[i][j-1]
                    for(int t = i-1; t >= dp[i][j-1][0] && bCloumns; t--)
                    {
                        if (matrix[t][j] == '0')
                        {
                            bCloumns = false;
                            nRows = t;
                        }
                    }
                    //dp[i-1][j-1]
                }
                else
                {
                    dp[i][j] = {i, j};
                }
                
            }
        }
    }
};
// @lc code=end

