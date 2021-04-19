/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */
#include <vector>
#include <conio.h>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int nResult = nums[0];
        int nCount = nums[0];
        int nSize = nums.size();
        for (int i = 1; i < nSize; i++)
        {
            if (nums[i] == 1)
            {
                nCount++;
            }
            else
            {
                nResult = nResult>=nCount?nResult:nCount;
                nCount=0;
            }
        }
        nResult = nResult>=nCount?nResult:nCount;
        return nResult;        
    }
};
int main()
{
    Solution sol;
	int nTemp[] = {1,1,0,1,1,1};
    int nVecSize = sizeof(nTemp)/sizeof(int);
	vector <int> nums(nTemp, nTemp+nVecSize);
	int result = sol.findMaxConsecutiveOnes(nums);
    cout << endl << result << endl;
    
	_getch();
	return 0;
}
// @lc code=end

