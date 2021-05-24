/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include<conio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int nMaxArea = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = 1;
                nMaxArea = 1;
            }
            else
            {
                dp[i][0] = 0;
            }            
        }
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == '1')
            {
                dp[0][j] = 1;
                nMaxArea = 1;
            }
            else
            {
                dp[0][j] = 0;
            }
        }
         for (int i = 1; i < matrix.size(); i++)
         {
             for (int j = 1; j < matrix[0].size(); j++)
             {
                 if (matrix[i][j] == '1')
                 {
                    int nMinArea = min(dp[i-1][j], dp[i][j-1]);
                    int nMinStep = sqrt(nMinArea); 
                    if (matrix[i-nMinStep][j-nMinStep] == '1')
                    {
                        dp[i][j] = (nMinStep+1)*(nMinStep+1);
                    }
                    else
                    {
                        dp[i][j] = nMinArea;
                    }
                    nMaxArea = max(nMaxArea, dp[i][j]);
                 }
                 else
                 {
                     dp[i][j] = 0;
                 }           
             }
         }
         return nMaxArea;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

    cout << sol.maximalSquare(matrix) << endl;
    _getch();
    return 0;
}
