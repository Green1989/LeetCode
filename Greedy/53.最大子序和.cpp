/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nResult = INT_MIN;
        int nNumSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {   
            nNumSum += nums[i];
            if (nResult < nNumSum)
            {
                nResult = nNumSum;
            }
            if (nNumSum < 0)
            {
                nNumSum = 0;
            }              
        }
        return nResult;                
    }
};
// @lc code=end

