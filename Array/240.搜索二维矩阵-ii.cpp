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
        int rows = matrix.size();
        int clumns = matrix[0].size();
        for (int j = 0; j < clumns && rows-(j+1) >= 0; j++)
        {
            if (target == matrix[rows-(j+1)][j])
            {
                return true;
            }
            else if(target < matrix[rows-(j+1)][j])
            {
                int left = 0;
                int right = rows-(j+1);
                while (left <= right)
                {
                    int mid = (right+left)/2;
                    if(target == matrix[mid][j])
                    {
                        return true;
                    }
                    else if (target < matrix[mid][j])
                    {
                        right = mid-1;
                    }
                    else
                    {
                        left = mid+1;
                    }                    
                }                
            }
            else if(target > matrix[rows-(j+1)][j])
            {
                int left = j;
                int right = clumns-1;
                while (left <= right)
                {
                    int mid = (right+left)/2;
                    if(target == matrix[rows-(j+1)][mid])
                    {
                        return true;
                    }
                    else if (target < matrix[rows-(j+1)][mid])
                    {
                        right = mid-1;
                    }
                    else
                    {
                        left = mid+1;
                    }                      
                }                
            }
        }     
        return false;   
    }
};
// @lc code=end

