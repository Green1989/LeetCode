/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size()-1; i > 0; i--)
        {
            if (nums[i] > nums[i-1])
            {
                nums.insert(nums.begin()+i-1, nums[nums.size()-1]);
                nums.pop_back();
                return;
            }            
        }
        sort(nums.begin(), nums.end());
    }
};
// @lc code=end

