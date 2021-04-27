/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];                        
        }        
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int nNeedEraseCount = 0;
        int nLastEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < nLastEnd)
            {
                nNeedEraseCount++;
                nLastEnd = nLastEnd<intervals[i][1]? nLastEnd:intervals[i][1];
            }
            else
            {
                nLastEnd = intervals[i][1];
            }
        }
        return nNeedEraseCount;
    }
};
// @lc code=end

