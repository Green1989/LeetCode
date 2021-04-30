/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int nDP[n+1];
        nDP[0] = 1;
        nDP[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            nDP[i] = nDP[i-1] + nDP[i-2];
        }
        return nDP[n];
    }
};
// @lc code=end

