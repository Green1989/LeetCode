/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 1; i < nums.size(); i++) {
            curDiff = nums[i] - nums[i - 1];
            // 出现峰值
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
        // if (nums.size() < 2)
        // {
        //     return nums.size();
        // }
        // int nCount = 1;
        // int a = nums[0];
        // int b;
        // int nIndex = 1;
        // for (nIndex = 1; nIndex < nums.size(); nIndex++)
        // {
        //     if (a != nums[nIndex])
        //     {
        //         b = nums[nIndex];
        //         nCount++;
        //         break;
        //     }
        // }        
        // for (int i = nIndex+1; i < nums.size(); i++)
        // {
        //     int c = nums[i];
        //     if (a>b && b<c)
        //     {
        //         a = b;
        //         b = c;
        //         nCount++;
        //         continue;
        //     }            
        //     else if (a<b && b>c)
        //     {
        //         a = b;
        //         b = c;
        //         nCount++;
        //         continue;
        //     }            
        // }
        // return nCount;
    }
};
// @lc code=end

