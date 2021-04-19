/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>
#include <conio.h>
#include <iostream>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int nSize = nums.size();
        if (nSize == 0)
        {
            return 0;
        }
        else if (nSize == 1)
        {
            if (nums[0] < target)
            {
                return 1;
            }
            else
            {
                return 0;
            }            
        }
        int nLeft = 0;
        int nRight = nSize-1;
        int nMid = 0;
        while (nRight >= nLeft)
        {
            nMid = (nLeft+nRight)/2;
            if (target == nums[nMid])
            {
                return nMid;
            }
            else if (target > nums[nMid])
            {
                nLeft = nMid + 1;
            }
            else
            {
                nRight = nMid;
            }            
            if (nLeft == nRight)
            {
                if (target == nums[nLeft])
                {
                    return nLeft;
                }
                else if (target > nums[nLeft])
                {
                    return nLeft+1;
                }
                else
                {
                    return nLeft;
                }
            }            
        }
        return 0;
    }
};
int main()
{
    Solution sol;
	int nTemp[] = {1,3,5,6};
	vector <int> nums(nTemp, nTemp+4);
	int target = 5;
	int result = sol.searchInsert(nums, target);
    cout << endl << result << endl;
    target = 2;
    result = sol.searchInsert(nums, target);
    cout << endl << result << endl;
    target = 7;
    result = sol.searchInsert(nums, target);
    cout << endl << result << endl;
    target = 0;
    result = sol.searchInsert(nums, target);
    cout << endl << result << endl;

    vector <int> nums1 = {1};
    result = sol.searchInsert(nums1, 1);
    cout << endl << result << endl;

	_getch();
	return 0;
}
// @lc code=end

