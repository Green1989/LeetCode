/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left < right)
        {
            int mid = (left+right)/2;
            if (target == nums[mid])
            {
                return mid;
            }
            if (left+1 == right)
            {
                if (target == nums[right])
                {
                    return right;
                }
                else
                {
                    return -1;
                }
            }            
            if(nums[left] < nums[mid])//连续区间
            {
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid-1;
                }
                else
                {
                    left = mid+1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        if (left == right && target == nums[left])
        {
            return left;
        }        
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << sol.search(nums, 3) << endl;
    _getch();
    return 0;
}