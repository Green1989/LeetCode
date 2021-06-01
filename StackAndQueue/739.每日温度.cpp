/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> vecRes(temperatures.size(), 0);
        stack<int> staTemp;
        for (int i = 0; i < temperatures.size()-1; i++)
        {
            if (temperatures[i] < temperatures[i+1])
            {
                vecRes[i] = 1;
                while (!staTemp.empty())
                {
                    if (temperatures[staTemp.top()] < temperatures[i+1])
                    {
                        vecRes[staTemp.top()] = i+1-staTemp.top();
                        staTemp.pop();
                    }
                    else
                    {
                        break;
                    }                    
                }                
            }
            else
            {
                staTemp.push(i);
            }            
        }        
        return vecRes;
    }
};
// @lc code=end

