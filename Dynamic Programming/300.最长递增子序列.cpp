/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums.size();
        }
        int nResult = 0;
        vector<int> dp(nums.size()+1, 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }                
            }
            nResult = nResult>dp[i]? nResult:dp[i];
        }
        return nResult;
    }
};
// @lc code=end

