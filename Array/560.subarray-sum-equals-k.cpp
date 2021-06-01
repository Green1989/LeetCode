/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include<conio.h>
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> recorde;
        recorde[0] = 1;
        int nSum = 0;
        int nCount = 0;
        for (auto &&n : nums)
        {
            nSum += n;
            if (recorde[nSum-k] > 0)
            {
                nCount += recorde[nSum-k];
                //recorde[nSum-k] = 0;
            }
            recorde[nSum]++;
        }
        return nCount;        
    }
};
// @lc code=endv

int main()
{
    Solution sol;
    vector<int> nums = {1,1,1};
    cout << sol.subarraySum(nums, 2) << endl;
    _getch();
    return 0;
}

