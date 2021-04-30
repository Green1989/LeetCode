/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];        
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> vecResult;
        if (intervals.size() == 0)
        {
            return vecResult;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> vecPack(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= vecPack[1])
            {
                vecPack[1] = vecPack[1]>intervals[i][1]? vecPack[1]:intervals[i][1];
            }
            else
            {
                vecResult.push_back(vecPack);
                vecPack = intervals[i];
            }                        
        }
        vecResult.push_back(vecPack);
        return vecResult;
    }
};
// @lc code=end

