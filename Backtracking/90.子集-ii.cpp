/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return vecResult;
    }
    void backtracking(vector<int>&nums, int start, vector<bool> used)
    {
        vecResult.push_back(vecPack);
        for (int i = start; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
            {
                continue;
            }            
            vecPack.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i+1, used);
            used[i] = false;
            vecPack.pop_back();
        }
    }
};
// @lc code=end

