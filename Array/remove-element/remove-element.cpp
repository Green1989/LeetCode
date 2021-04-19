/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>
#include <conio.h>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        int count = nums.size();
        for (int i = 0; i < count; i++)
        {
            if (nums[i] != val)
            {
                nums[index] = nums[i];
                index++;
            }            
        }
        return index;        
    }
};
int main()
{
    Solution sol;
	int nTemp[] = {3,2,2,3};
	vector <int> nums(nTemp, nTemp+4);
	int target = 3;
	int result = sol.removeElement(nums, target);
    cout << endl << result << ",nums=" << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ",";
    }

    int nTemp1[] = {0,1,2,2,3,0,4,2};
	vector <int> nums1(nTemp1, nTemp1+8);
	target = 2;
	result = sol.removeElement(nums1, target);
    cout << endl << result << ",nums=" << endl;
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << ",";
    }
    
	_getch();
	return 0;
}
// @lc code=end

