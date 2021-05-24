/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {      
        int nMinmajorityElementCount = nums.size()/2 + 1;
        unordered_map<int, int> mapNums;
        for (auto &&n : nums)
        {
            if (mapNums.find(n) == mapNums.end())
            {
                mapNums[n] = 1;
            }
            else
            {
                mapNums[n]++;
                if (mapNums[n] >= nMinmajorityElementCount)
                {
                    return n;
                }                
            }
        }
        return nums[0];
        // int nMaxCount = INT_MIN;
        // int nResult = 0;
        // for (auto &&mappair : mapNums)
        // {
        //     if (nMaxCount < mappair.second)
        //     {
        //         nMaxCount = mappair.second;
        //         nResult = mappair.first;
        //     }            
        // }
        // return nResult;
    }
};
// @lc code=end

