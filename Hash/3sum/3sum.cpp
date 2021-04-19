/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <conio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vecResult;
        if(nums.size() < 3)
        {
            return vecResult;
        }
        sort(nums.begin(), nums.end());
        int nLeft, nRight;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
            {
                return vecResult;
            }
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }                        
            nLeft = i + 1;
            nRight = nums.size() - 1;
            while (nLeft < nRight)
            {
                if (nums[i] + nums[nLeft] + nums[nRight] < 0)
                {
                    nLeft++;
                }
                else if(nums[i] + nums[nLeft] + nums[nRight] > 0)
                {
                    nRight--;
                }
                else
                {
                    vecResult.push_back(vector<int> {nums[i], nums[nLeft], nums[nRight]});
                    while (nLeft < nRight && nums[nLeft] == nums[nLeft+1])
                    {
                        nLeft++;
                    }
                    while (nLeft  < nRight && nums[nRight] == nums[nRight-1])
                    {
                        nRight--;
                    }                
                    nLeft++;
                    nRight--;
                }
            }                        
        }        
        return vecResult;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> vecResult;
	vector <int> vecNums = {-1,0,0,0,1,2,-1,-4};
    for (int i = 0; i < vecNums.size(); i++)
    {
        cout << vecNums[i] << ", ";
    }
    cout << endl;

    vecResult = sol.threeSum(vecNums);

    for (int i = 0; i < vecNums.size(); i++)
    {
        cout << vecNums[i] << ", ";
    }
    cout << endl;

    for (int i = 0; i < vecResult.size(); i++)
    {
        for (int j = 0; j < vecResult[0].size(); j++)
        {
            cout << vecResult[i][j] << ", ";
        }
        cout << endl;        
    }
	_getch();
	return 0;
}
// @lc code=end

