/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
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
    vector<vector<int>> combine(int n, int k) {
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
            vecResult.push_back(vecPack);
            return ;          
        }
        for (int i = startIndex; i <= n; i++)
        {
            vecPack.push_back(i);
            backtracking(i+1, n, k);
            vecPack.pop_back();
        }
    }
};
// int main()
// {
//     Solution sol;
//     vector<vector<int>> vecResult;
// 	vecResult = sol.combine(6, 3);
// 	for (int i = 0; i < vecResult.size(); i++)
//     {
//         for (int j = 0; j < vecResult[i].size(); j++)
//         {
//             cout << vecResult[i][j] << ", ";
//         }
//         cout << endl;        
//     }

//     cout << "size = " << vecResult.size();
    
// 	_getch();
// 	return 0;
// }
// @lc code=end

