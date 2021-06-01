/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int nLeft = 0;
        int nRight = nums.size()-1;
        for (; nLeft < nums.size(); nLeft++)
        {
            int i = nLeft+1;
            for (; i < nums.size(); i++)
            {
                if (nums[i] < nums[nLeft])
                {
                    break;
                }
            }
            if (i < nums.size())
            {
                break;
            }
        }
        for (;nRight >= nLeft; nRight--)
        {
            int i = nRight - 1;
            for (; i >= nLeft; i--)
            {
                if (nums[i] > nums[nRight])
                {
                    break;
                }                
            }
            if (i >= nLeft)
            {
                break;
            }
        }
        return nRight - nLeft + 1;
    }
};
// @lc code=end

