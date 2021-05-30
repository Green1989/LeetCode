/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> vecRes;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i])-1;
            nums[index] = (-1)*abs(nums[index]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                vecRes.push_back(i+1);
            }            
        }
        return vecRes;   
    }
};
// @lc code=end

