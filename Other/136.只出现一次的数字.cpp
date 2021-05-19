/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nExistOnce = 0;
        for (auto &&n : nums)
        {
            nExistOnce ^= n;
        }
        return nExistOnce;
    }
};
// @lc code=end

