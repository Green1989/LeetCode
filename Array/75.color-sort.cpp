/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include<conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int left = 0;
        // int right = nums.size() - 1;
        // while (left < right)
        // {
        //     if(nums[left] == 2 && nums[right] == 0)
        //     {
        //         swap(nums[left], nums[right]);
        //         left++;
        //         right--;
        //     }
        //     else if(nums[left] == 2)
        //     {
        //         right--;
        //     }
        //     else if(nums[right] == 0)
        //     {
        //         left++;
        //     }
        //     else
        //     {
        //         left++;
        //         right--;                
        //     }            
        // }
        // if (nums[left] == 2)
        // {
        //     nums.erase(nums.begin()+left);
        //     nums.push_back(2);
        // }
        // else if (nums[left] == 0)
        // {
        //     nums.erase(nums.begin()+left);
        //     nums.insert(nums.begin(), 0);
        // }       
        int num0 = 0, num1 = 0, num2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                nums[num2++] = 2;
                nums[num1++] = 1;
                nums[num0++] = 0;
            }else if(nums[i] == 1) {
                nums[num2++] = 2;
                nums[num1++] = 1;
            }else {
                nums[num2++] = 2;
            }
        }        
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    for (auto &&n : nums)
    {
        cout << n << ", ";
    }
    
    _getch();
    return 0;
}