/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include<algorithm>
#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> vecResult;
    vector<int> vecPack;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //vector<bool> used(nums.size(), false);
        //sort(nums.begin(), nums.end());
        backtracking(nums, 0/*, used*/);
        return vecResult;
    }
    void backtracking(vector<int>&nums, int start/*, vector<bool> used*/)
    {
        if (vecPack.size() > 1)
        {
            vecResult.push_back(vecPack);
        }
        unordered_set<int> setUsed;
        for (int i = start; i < nums.size(); i++)
        {
            // if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
            // {
            //     continue;
            // }
            if (vecPack.size() > 0 && vecPack.back() > nums[i])
            {
                continue;
            }
            if (setUsed.find(nums[i]) != setUsed.end())
            {
                continue;
            }
            
            setUsed.insert(nums[i]);
            vecPack.push_back(nums[i]);
            //used[i] = true;
            backtracking(nums, i+1/*, used*/);
            //used[i] = false;
            vecPack.pop_back();
        }
    }
};
// @lc code=end

