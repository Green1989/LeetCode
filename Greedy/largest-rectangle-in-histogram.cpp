/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int nResult = 0;
        int nMaxHeight = 0;
        heights.push_back(0);
        for(int i = 0; i < heights.size()-1; i++)
        {
            int index = i;
            while (heights[i+1] < heights[index])
            {
                nResult = max(nResult, heights[index]*(i+1-index));
                if (index-1 >= 0)
                {
                    if (heights[index-1] < heights[i+1])
                    {
                        heights[index] = heights[i+1];
                    }
                    else
                    {
                        heights[index] = heights[index-1];
                        index--;
                    }
                }
                else
                {
                    heights[index] = heights[i+1];
                    break;
                }
            }
            if (i - index > 0)
            {
                for(int j = index+1; j < i+1; j++)
                {
                    heights[j] = heights[index];
                }
            }            
        }
        return nResult;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> heights = {4,2,0,3,2,5};
    int nRet = sol.largestRectangleArea(heights);

    cout << nRet << endl;
	_getch();
	return 0;
}