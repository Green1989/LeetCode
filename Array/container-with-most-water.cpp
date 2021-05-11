/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include<conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int nLeft = 0;
        int nRight = height.size()-1;
        int nResult1 = min(height[nLeft], height[nRight]) * (nRight-nLeft);
        int nResult2;
        while (nLeft+1 < nRight)
        {
            if (height[nLeft] < height[nRight])
            {
                while (nLeft+1 < nRight && height[nLeft+1] < height[nLeft])
                {
                    nLeft++;
                }
                if (nLeft+1 < nRight)
                {
                    nLeft++;
                    nResult2 = min(height[nLeft], height[nRight]) * (nRight-nLeft);
                    nResult1 = max(nResult1, nResult2);
                }                
            } 
            else
            {
                while (nLeft < nRight-1 && height[nRight-1] < height[nRight])
                {
                    nRight--;
                }
                if (nLeft < nRight-1)
                {
                    nRight--;
                    nResult2 = min(height[nLeft], height[nRight]) * (nRight-nLeft);
                    nResult1 = max(nResult1, nResult2);
                }                  
            }           
        }        
        return nResult1;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl;
    _getch();
    return 0;
}