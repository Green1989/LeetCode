/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums.size();
        }        
        int nResult = 1;
        // int nCount = 1;
        // for (int i = 0; i < nums.size()-1; i++)
        // {
        //     if(nums[i] < nums[i+1])
        //     {
        //         nCount++;
        //     }
        //     else
        //     {
        //         nResult = nResult>nCount? nResult:nCount;
        //         nCount = 1;
        //     }
        // }
        // if (nCount != 1)
        // {
        //     nResult = nResult>nCount? nResult:nCount;
        // }        
        // return nResult;
        
        vector<int> dp(nums.size()+1, 1);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i-1])
            {
                dp[i] = dp[i-1] + 1;
            }
            nResult = nResult>dp[i]? nResult:dp[i];            
        }
        return nResult;
    }
};
// @lc code=end

