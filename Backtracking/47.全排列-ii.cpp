/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> vecResult;
    vector<int> vecPack;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> vecUsed(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, vecUsed);
        return vecResult;
    }
    void backtracking(vector<int>&nums, vector<bool> vecUsed)
    {
        if (vecPack.size() == nums.size())
        {
            vecResult.push_back(vecPack);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (vecUsed[i])
            {
               continue;
            }
            if (i > 0 && nums[i] == nums[i-1] && vecUsed[i-1] == false)
            {
                continue;
            }
            
            vecPack.push_back(nums[i]);
            vecUsed[i] = true;
            backtracking(nums, vecUsed);
            vecUsed[i] = false;
            vecPack.pop_back();
        }
    }
};
// @lc code=end

