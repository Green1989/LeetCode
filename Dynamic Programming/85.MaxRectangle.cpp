/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include<conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
        {
            return 0;
        }
        
        int nResult = 0;
        vector<vector<vector<int>>> dp(matrix.size(), vector<vector<int>>(matrix[0].size(), vector<int>(2)));
        int index = -1;
        for (int i = 0; i < dp[0].size(); i++)
        {
            if (matrix[0][i] == '0')
            {
                index = i;
                dp[0][i] = {-1, -1};
            }
            else
            {
                dp[0][i] = {0, index+1};
                nResult = max(nResult, i-index);
            }            
        }
        index = -1;
        for (int i = 0; i < dp.size(); i++)
        {
            if (matrix[i][0] == '0')
            {
                index = i;
                dp[i][0] = {-1, -1};
            }
            else
            {
                dp[i][0] = {index+1, 0};
                nResult = max(nResult, i-index);
            }           
        }
        for (int i = 1; i < dp.size(); i++)
        {         
            for (int j = 1; j < dp[i].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    int i_1j = 0;
                    int ij_1 = 0;
                    int i_1j_1 = 0;
                    bool bRows = true;
                    bool bCloumns = true;             
                    int nRows = dp[i][j-1][0];
                    int nCloumns = dp[i-1][j][1];          
                    //dp[i-1]][j]
                    if (dp[i-1][j][0] != -1 && dp[i-1][j][1] != -1)
                    {
                        for(int k = j-1; k >= dp[i-1][j][1] && bRows; k--)
                        {
                            if (matrix[i][k] == '0')
                            {
                                bRows = false;
                                nCloumns = k+1;
                            }
                        }
                        i_1j = (i-dp[i-1][j][0]+1)*(j-nCloumns+1);
                    }
                    
                    
                    //dp[i][j-1]
                    if (dp[i][j-1][0] != -1 && dp[i][j-1][1] != -1)
                    {
                        for(int t = i-1; t >= dp[i][j-1][0] && bCloumns; t--)
                        {
                            if (matrix[t][j] == '0')
                            {
                                bCloumns = false;
                                nRows = t+1;
                            }
                        }
                        ij_1 = (i-nRows+1)*(j-dp[i][j-1][1]+1);
                    }
                    
                    //dp[i-1][j-1]                
                    int nRows0 = dp[i-1][j-1][0];
                    int nCloumns0 = dp[i-1][j-1][1];
                    if (dp[i-1][j-1][0] != -1 && dp[i-1][j-1][1] != -1)
                    {
                        bool bRows0 = true;
                        bool bCloumns0 = true;
                        for(int k = nCloumns; k >= dp[i-1][j-1][1] && bRows0; k--)
                        {
                            if (matrix[i][k] == '0')
                            {
                                bRows0 = false;
                                nCloumns0 = k+1;
                            }
                        }
                        for(int t = nRows; t >= dp[i-1][j-1][0] && bCloumns0; t--)
                        {
                            if (matrix[t][j] == '0')
                            {
                                bCloumns0 = false;
                                nRows0 = t+1;
                            }
                        }
                        i_1j_1 = (i-nRows0+1)*(j-nCloumns0+1);
                    }
                    if (i_1j > 0 && i_1j > ij_1 && i_1j > i_1j_1)
                    {
                        nResult = max(nResult, i_1j);
                        dp[i][j][0] = dp[i-1][j][0];
                        dp[i][j][1] = nCloumns;
                    }
                    else if (ij_1 > 0 && ij_1 >= i_1j && ij_1 > i_1j_1)
                    {
                        nResult = max(nResult, ij_1);
                        dp[i][j][0] = nRows;
                        dp[i][j][1] = dp[i][j-1][1];                        
                    }
                    else
                    {                        
                        if (i_1j_1 > 0)
                        {
                            nResult = max(nResult, i_1j_1);
                            dp[i][j][0] = nRows0;
                            dp[i][j][1] = nCloumns0;
                        }
                        else
                        {
                            nResult = max(nResult, 1);
                            dp[i][j] = {i, j};
                        }                        
                    }
                }
                else
                {
                    dp[i][j] = {-1, -1};
                }
                
            }
        }

        // for (int i = 0; i < dp.size(); i++)
        // {
        //     for (int j = 0; j < dp[i].size(); j++)
        //     {
        //         cout << "(" << dp[i][j][0] << "," << dp[i][j][1] << "), ";
        //     }
        //     cout << endl;
        // }
        
        return nResult;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << sol.maximalRectangle(matrix) << endl;
    _getch();
    return 0;
}

