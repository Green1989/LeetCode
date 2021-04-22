/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <algorithm>
#include <conio.h>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> vecResult;
    vector<int> vecPack;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> vecUsed(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, vecUsed);
        return vecResult;
    }
    void backtracking(vector<int>& candidates, int target, int start, vector<bool> vecUsed)
    {
        int sum = target;
        for (int i = 0; i < vecPack.size() && sum >= 0; i++)
        {
            sum -= vecPack[i];            
        }
        if (sum <= 0)
        {
            if (sum == 0)
            {
                vecResult.push_back(vecPack);
            }            
            return;
        }                
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > 0 && candidates[i] == candidates[i-1] && vecUsed[i-1] == false)
            {
                continue;
            }
            vecPack.push_back(candidates[i]);
            vecUsed[i] = true;
            backtracking(candidates, target, i+1, vecUsed);
            vecUsed[i] = false;
            vecPack.pop_back();
        }
    }
};
// int main()
// {
//     Solution sol;
//     vector<vector<int>> vecResult;
// 	vector <int> vecNums = {10,1,2,7,6,1,5};
//     for (int i = 0; i < vecNums.size(); i++)
//     {
//         cout << vecNums[i] << ", ";
//     }
//     cout << endl;

//     int target = 8;
//     vecResult = sol.combinationSum2(vecNums, target);

//     for (int i = 0; i < vecResult.size(); i++)
//     {
//         for (int j = 0; j < vecResult[i].size(); j++)
//         {
//             cout << vecResult[i][j] << ", ";
//         }
//         cout << endl;        
//     }
// 	_getch();
// 	return 0;
// }

// @lc code=end

