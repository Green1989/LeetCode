/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include<map>
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> vecResult;
    unordered_map<string, map<string, int>> targets;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vecResult.push_back("JFK");
        for (auto &&vec : tickets)
        {
            targets[vec[0]][vec[1]]++;
        }
        backtracking(tickets);
        return vecResult;        
    }
    bool backtracking(vector<vector<string>>& tickets)
    {
        if (vecResult.size() == tickets.size() + 1)
        {
            return true;
        }
        for (auto &&target : targets[vecResult.back()])
        {
            if (target.second > 0)
            {
                vecResult.push_back(target.first);
                target.second--;
                if(backtracking(tickets))
                {
                    return true;
                }
                vecResult.pop_back();
                target.second++;
            }    
        }
        return false;
    }
};
// @lc code=end

