/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nCurIndex = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            nCurIndex = (i+nums[i]) > nCurIndex ? (i+nums[i]):nCurIndex;
            if (nums[i] == 0 && nCurIndex <= i)
            {
                return false;
            }             
        }
        return true;
    }
};
// @lc code=end

