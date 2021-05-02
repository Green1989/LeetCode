/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int nSum = 0;
        for (auto &&n : stones)
        {
            nSum += n;
        }

        vector<int> vecDP(nSum/2+1, 0);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = nSum/2; j >= stones[i]; j--)
            {
                vecDP[j] = max(vecDP[j], vecDP[j-stones[i]]+stones[i]);                
            }
        }
        return nSum - vecDP[nSum/2]*2;
    }
};
// @lc code=end

