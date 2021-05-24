/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int nR = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            nR *= nums[i+1];
            ans[i] = ans[i] * nR;
        }
        return ans;
    }
};
// @lc code=end

