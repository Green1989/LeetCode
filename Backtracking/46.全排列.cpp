/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> vecResult;
    vector<int> vecPack;
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vecUsed(nums.size(), false);
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
            vecPack.push_back(nums[i]);
            vecUsed[i] = true;
            backtracking(nums, vecUsed);
            vecUsed[i] = false;
            vecPack.pop_back();
        }
    }
};
// @lc code=end

