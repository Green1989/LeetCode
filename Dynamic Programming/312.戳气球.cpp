/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */
#include<map>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
         int nCount = nums.size() - 2;
         int nResult = 0;
         while (nCount > 0)
         {
            int nMinNum = INT_MAX;
            int nIndex = -1;             
            for (int i = 1; i < nums.size()-1; i++)
            {
                if (nums[i] >= 0)
                {
                    if (nMinNum > nums[i])
                    {
                        nMinNum = nums[i];
                        nIndex = i;
                    }
                }
            }
            if (nIndex > 0)
            {
                int nLeft = nIndex - 1;
                while (nLeft >= 0 && nums[nLeft] < 0)
                {
                    nLeft--;
                }
                int nRight = nIndex + 1;
                while (nRight < nums.size() && nums[nRight] < 0)
                {
                    nRight++;
                }
                nResult += (nums[nLeft] * nums[nIndex] *nums[nRight]);     
                nums[nIndex] = -1;
            }
            nCount--;
         }
         nResult += (nums[0]*nums[nums.size()-1]);
         nResult += max(nums[0], nums[nums.size()-1]);   
         return nResult;     
    }
};
// @lc code=end

