/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> vecResult;
    vector<int> vecPack;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return vecResult;
    }
    void backtracking(vector<int>&nums, int start)
    {
        vecResult.push_back(vecPack);
        for (int i = start; i < nums.size(); i++)
        {
            vecPack.push_back(nums[i]);
            backtracking(nums, i+1);
            vecPack.pop_back();
        }
    }
};
// @lc code=end

