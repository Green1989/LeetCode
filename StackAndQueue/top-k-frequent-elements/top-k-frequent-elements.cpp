/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <conio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
// @lc code=start
class MyComparison
{
public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.second > rhs.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> vecRes;
        unordered_map<int, int> map;
        for (auto &&n : nums)
        {
            map[n]++;
        }
        priority_queue <pair<int, int>, vector<pair<int, int>>, MyComparison> pri_queue;
        for (auto &&itor : map)
        {
            pri_queue.push(itor);
            while (pri_queue.size()>k)
            {
                pri_queue.pop();
            }            
        }
        while (!pri_queue.empty())
        {
            vecRes.push_back(pri_queue.top().first);
            pri_queue.pop();
        }                
        return vecRes;
    }
};
// int main()
// {
//     Solution sol;
//     vector<int> nums = {1,1,1,2,2,3};
//     vector<int> vecRes = sol.topKFrequent(nums, 2);
//     for (auto &&n : nums)
//     {
//         cout << n << ", ";
//     }  
//     cout << endl;
//     for (auto &&n : vecRes)
//     {
//         cout << n << ", ";
//     }  
//     cout << endl;
//     _getch();
//     return 0;
// }
// @lc code=end

