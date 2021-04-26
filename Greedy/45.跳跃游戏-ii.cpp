/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int nCurMax = 0;
        int nNextMax = 0;
        int nStepCount = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            nNextMax = max(i+nums[i], nNextMax);
            if (i == nCurMax)
            {
                nCurMax = nNextMax;
                nStepCount++;
            }
        }
        return nStepCount;        
    }

};
// @lc code=end

