/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <conio.h>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> vecResult;
    vector<int> vecPack;    
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(1, n, k);
        return vecResult;
    }
    void backtracking(int startIndex, int n, int k)
    {
        if (vecPack.size()+(n-startIndex+1) < k)//剩余的n-startIndex+1个数量不够组成一个完整的集合
        {
            return ;
        }
        
        if (vecPack.size() == k)
        {
            for (int i = 0; i < k && n >=0; i++)
            {
                n -= vecPack[i];
            }
            if (n == 0)
            {
                vecResult.push_back(vecPack);
            }
            return ;          
        }
        for (int i = startIndex; i <= 9; i++)
        {
            vecPack.push_back(i);
            backtracking(i+1, n, k);
            vecPack.pop_back();
        }
    }

};
// @lc code=end

