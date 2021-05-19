/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int nLongest = 0;
        for (auto &&num : numsSet)
        {
            if (!numsSet.count(num-1))
            {
                int curNum = num+1;
                while (numsSet.count(curNum))
                {
                    curNum++;
                }
                nLongest = max(nLongest, curNum-num);
            }
        }
        return nLongest;
    }
};
// @lc code=end

