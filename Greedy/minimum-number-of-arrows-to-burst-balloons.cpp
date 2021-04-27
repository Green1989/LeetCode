/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <conio.h>
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
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0)
        {
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        int nShotsCount = 1;
        int nLastEnd = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > nLastEnd)
            {
                nShotsCount++;
                nLastEnd = points[i][1];
            }
            else
            {
                nLastEnd = nLastEnd<points[i][1]? nLastEnd:points[i][1];              
            }
        }
        return nShotsCount;
    }
};
// int main()
// {
//     Solution sol;
//     vector<vector<int>> points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
//     int nRet = sol.findMinArrowShots(points);
//     cout << nRet << endl;
// 	_getch();
// 	return 0;
// }
// @lc code=end

