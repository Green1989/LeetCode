/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int nCount = 0;
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                nCount = nCount>dp[i][j]? nCount:dp[i][j];
            }            
        }        
        return nCount;
    }

};
// @lc code=end

