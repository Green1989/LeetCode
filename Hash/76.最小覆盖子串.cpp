/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include<unordered_map>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapT;
        unordered_map<char, int> mapT0;
        for (auto &&c : t)
        {
            if (mapT.find(c) == mapT.end())
            {
                mapT[c] = 1;
            }
            else
            {
                mapT[c]++;
            }
        }
        mapT0 = mapT;
        int pos1 = 0;
        int pos2 = 0;
        int curSize = s.size();
        for(int i = t.size()-1; i < s.size(); i++)
        {
            int nCount = 0;
            mapT0 = mapT;
            for(int j = i; j >= 0; j--)
            {
                if (mapT0.find(s[j]) == mapT0.end())
                {
                    nCount++;
                }
                else
                {
                    mapT0[s[j]]--;
                    if (mapT0[s[j]] < 0)
                    {
                        break;
                    }
                }
                if (nCount > curSize)
                {
                    break;
                }
                
            }
        }
    }
};
// @lc code=end

