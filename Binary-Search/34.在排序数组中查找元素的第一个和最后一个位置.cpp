/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int find = -1;
        while (left <= right)
        {
            int mid = (left+right)/2;
            if (target == nums[mid])
            {
                find = mid;
            }
            if (target >= nums[left] && target < nums[mid])
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        if (find >= 0)
        {
            right = find;
            while (right+1<nums.size() && target == nums[right+1])
            {
                right++;
            }
            left = find;
            while (left-1>=0 && target == nums[left-1])
            {
                left--;
            }            
        }
        else
        {
            left = -1;
            right = -1;
        }
        return vector<int>{left, right};
    }
};
// @lc code=end

