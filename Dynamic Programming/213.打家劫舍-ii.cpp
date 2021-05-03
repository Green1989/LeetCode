/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        
        vector<int> dp(nums.size()+1, 0);
        dp[0] = nums[0];
        dp[1] = nums[1]>nums[0]? nums[1]:nums[0];
        
        for (int i = 2; i < nums.size()-1; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int nMax = dp[nums.size()-2];
        dp[0] = 0;//把nums[0]当做0
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return max(nMax, dp[nums.size()-1]);
    }
};
// @lc code=end

