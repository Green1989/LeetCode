/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <conio.h>
#include <iostream>
#include <numeric>
using namespace std;
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
		for (int i = 0; i < nums.size()-1; i++)
		{
			for (int j = i+1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					return {i ,j};
				}				
			}			
		}
        return {0, 0};
    }
};
int main()
{
    Solution sol;
	int nTemp[] = {2,7,9,3,1};
	vector <int> nums(nTemp, nTemp+5);
    vector <int> result{0, 0};
	int target = 11;
	result = sol.twoSum(nums, target);
	cout << endl << result[0] << ", " << result[1] << endl;

	_getch();
	return 0;
}
// @lc code=end

