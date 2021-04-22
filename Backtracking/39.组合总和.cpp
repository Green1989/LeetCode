/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> vecResult;
    vector<int> vecPack;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);
        return vecResult;
    }
    void backtracking(vector<int>& candidates, int target, int start)
    {
        if (start >= candidates.size())
        {
            return;
        }
        int sum = target;
        for (int i = 0; i < vecPack.size() && sum >= 0; i++)
        {
            sum -= vecPack[i];            
        }
        if (sum <= 0)
        {
            if (sum == 0)
            {
                vecResult.push_back(vecPack);
            }            
            return;
        }                
        for (int i = start; i < candidates.size(); i++)
        {
            vecPack.push_back(candidates[i]);
            backtracking(candidates, target, i);
            vecPack.pop_back();
        }
    }
};
// @lc code=end

