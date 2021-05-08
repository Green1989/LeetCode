/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int nCount = nums.size()+1;
        int nStart = 0;
        int nSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nSum += nums[i];
            while(nSum >= target)
            {
                nCount = min(nCount, i - nStart + 1);
                nSum -= nums[nStart];
                nStart++;
            }
        }
        if(nCount == nums.size()+1)
            return 0;
        return nCount;        
    }
};
// @lc code=end

