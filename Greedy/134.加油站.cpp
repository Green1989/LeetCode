/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); i++)
        {
            int nLast = 0;
            int j = i;
            for (; j < i + gas.size(); j++)
            {
                nLast += (gas[j%gas.size()]-cost[j%gas.size()]);
                if (nLast < 0)
                {
                    break;
                }
            }
            if (j == i + gas.size())
            {
                return j%gas.size();
            }
        }
        return -1;        
    }
};
// @lc code=end

