/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> vecResult;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vecResult.push_back("JFK");
        vector<bool> used(tickets.size(), false);
        backtracking(tickets, "JFK", used);
        return vecResult;
    }
    void backtracking(vector<vector<string>>& tickets, string target, vector<bool> used)
    {
        if (vecResult.size() == tickets.size() + 1)
        {
            return;
        }
        //string best = getBest(tickets, target);
        string best = "ZZZ";
        int index = 0;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (tickets[i][0] == target)
            {
                if (tickets[i][1] < best && used[i] == false)
                {
                    best = tickets[i][1];
                    index = i;
                }
            }
        }
        used[index] = true;
        vecResult.push_back(best);
        backtracking(tickets, best, used);
        
    }
    string getBest(vector<vector<string>>& tickets, string target)
    {
        string best = "ZZZ";
        for (int i = 0; i < tickets.size(); i++)
        {
            if (tickets[i][0] == target)
            {
                if (tickets[i][1] < best)
                {
                    best = tickets[i][1];
                }
            }
        }
        return best;
    }
};
// @lc code=end

