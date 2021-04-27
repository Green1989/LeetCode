/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n5dollarCount = 0;
        int n10dollarCount = 0;
        int n20dollarCount = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                n5dollarCount++;
            }
            else if (bills[i] == 10)
            {
                n5dollarCount--;
                n10dollarCount++;
            }
            else
            {
                if (n10dollarCount > 0)
                {
                    n10dollarCount--;
                    n5dollarCount--;
                }
                else
                {
                    n5dollarCount -= 3;
                }                
            }
            if (n5dollarCount < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

