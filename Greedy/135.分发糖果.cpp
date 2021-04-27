/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> vecCandy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i-1])
            {
                vecCandy[i] = vecCandy[i-1] + 1;
            }            
        }
        for (int i = ratings.size()-2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i+1])
            {
                vecCandy[i] = max(vecCandy[i], vecCandy[i+1]+1);
            }
        }
        int nCandyCount = 0;
        for (auto &&n : vecCandy)
        {
            nCandyCount += n;
        }        
        return nCandyCount;
    }
};
// @lc code=end

