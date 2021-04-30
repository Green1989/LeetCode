/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int fib(int n) {
        // if (n == 0)
        // {
        //     return 0;
        // }
        // if (n == 1)
        // {
        //     return 1;
        // }
        // return fib(n-1)+fib(n-2);    
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        int nResult = 0;
        int fib0 = 0;
        int fib1 = 1;
        for (int i = 2; i < n+1; i++)
        {
            nResult = fib1 + fib0;
            fib0 = fib1;
            fib1 = nResult;
        }
        return nResult;
    }
};
// @lc code=end

