/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int nSum = 0;
        for (auto &&n : nums)
        {
            nSum += n;
        }
        if (nSum % 2 != 0)
        {
            return false;
        }
        vector<int> vecDP(nSum/2+1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = nSum/2; j >= nums[i]; j--)
            {
                vecDP[j] = max(vecDP[j], vecDP[j-nums[i]]+nums[i]);                
            }
        }
        return vecDP[nSum/2] == nSum/2;                                
    }
};
// @lc code=end

