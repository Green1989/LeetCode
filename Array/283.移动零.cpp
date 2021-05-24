/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nZeroCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                nZeroCount++;
            }
            else
            {
                nums[i-nZeroCount] = nums[i];                
            }
        }
        while (nZeroCount>0)
        {
            nums[nums.size()-nZeroCount] = 0;
            nZeroCount--;
        }
    }
};
// @lc code=end

