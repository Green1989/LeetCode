/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        dp[0] = nums[0];
        if (nums.size() > 1)
        {
            dp[1] = nums[1]>nums[0]? nums[1]:nums[0];
        }        
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];        
    }
};
// @lc code=end

