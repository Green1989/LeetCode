/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

#include <conio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0)
        {
            return 0;
        }        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = s.size()-1;
        for (int i = g.size()-1; i >= 0; i--)
        {
            if(g[i] <= s[j])
            {
                j--;
                if (j < 0)
                {
                    break;
                }                
            }
        }
        return s.size()-1-j;        
    }
};
// int main()
// {
//     Solution sol;
//     vector<int> g = {1,2};
//     vector<int> s = {1,2,3};
//     int nRet = sol.findContentChildren(g, s);

//     cout << nRet << endl;
// 	_getch();
// 	return 0;
// }
// @lc code=end

