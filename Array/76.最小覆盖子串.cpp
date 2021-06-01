/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
        {
            return "";
        }
        unordered_map<char, int> t_map;
        for (auto &&c : t)
        {
            if (t_map.find(c) == t_map.end())
            {
                t_map[c] = 1;
            }
            else
            {
                t_map[c]++;
            }
        }
        int nCount = 0;
        int nLeft = 0;
        while (nLeft < s.size())
        {
            if (t_map.find(s[nLeft]) != t_map.end())
            {
                t_map[s[nLeft]]--;
                nCount++;
                break;
            }                
            nLeft++;        
        }
        if (nCount == t.size())
        {
            return s.substr(nLeft, nCount);
        }
        int nRight = nLeft;
        while (nRight < s.size())
        {
            if (t_map.find(s[nRight]) != t_map.end() && t_map[s[nRight]] > 0)
            {
                t_map[s[nRight]]--;
                nCount++;
                if (nCount == t.size())
                {
                    break;
                }                
            }
            nRight++;
        }
        if (nCount < t.size())
        {
            return "";
        }
        string strRes = s.substr(nLeft, nRight-nLeft+1);
        while (nLeft < s.size() && nRight < s.size())
        {
            if (t_map.find(s[nLeft]) == t_map.end())
            {
                while (nLeft < s.size() && t_map.find(s[nLeft]) == t_map.end())
                {
                    nLeft++;
                }
                strRes = s.substr(nLeft, nRight-nLeft+1);
                continue;
            }
            else
            {                   
                if (nLeft < s.size())
                {
                    t_map[s[nLeft]]++;
                    nCount--;
                }       
                nLeft++;                        
            }
            while (nLeft < s.size() && nRight < s.size() && nCount < t.size())
            {
                if (t_map.find(s[nLeft]) != t_map.end())
                {
                    t_map[s[nLeft]]++;
                    nCount--;
                }
                nLeft++; 
                nRight++;
                if (t_map.find(s[nRight]) != t_map.end() && t_map[s[nRight]] > 0)
                {
                    t_map[s[nRight]]--;
                    nCount++;
                }                                        
            }
            if (nCount == t.size())
            {
                strRes = s.substr(nLeft, nRight-nLeft+1);
            }            
        }
        return strRes;
    }
};
// @lc code=end

