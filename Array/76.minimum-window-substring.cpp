/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include<conio.h>
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
        unordered_map<char, int> backups_map;
        for (auto &&c : t)
        {
            if (t_map.find(c) == t_map.end())
            {
                t_map[c] = 1;
                backups_map[c] = 1;
            }
            else
            {
                t_map[c]++;
                backups_map[c]++;
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
        while (nRight+1 < s.size())
        {
            nRight++;
            if (t_map.find(s[nRight]) != t_map.end())
            {
                if (t_map[s[nRight]] > 0)
                {
                    nCount++;
                }
                t_map[s[nRight]]--;                
                if (nCount == t.size())
                {
                    break;
                }
            }
        }
        if (nCount < t.size())
        {
            return "";
        }
        string strRes = s.substr(nLeft, nRight-nLeft+1);
        if (nRight-nLeft+1 == t.size())
        {
            return strRes;
        }
        
        while (nLeft < s.size() && nRight < s.size())
        {
            if (t_map.find(s[nLeft]) == t_map.end())
            {
                while (nLeft < s.size() && t_map.find(s[nLeft]) == t_map.end())
                {
                    nLeft++;
                }
                strRes = s.substr(nLeft, nRight-nLeft+1);
                if (nRight-nLeft+1 == t.size())
                {
                    return strRes;
                }
                continue;
            }
            else
            {
                if (t_map[s[nLeft]] < 0)
                {
                    t_map[s[nLeft]]++;
                    nLeft++;
                    strRes = s.substr(nLeft, nRight-nLeft+1); 
                    continue;
                }
                t_map[s[nLeft]]++;
                nCount--;
                nLeft++;
                if (nRight + 1 >= s.size())
                {
                    break;
                }
                // int nLeftCount = 0;
                // for (int i = nLeft+1; i <= nRight; i++)
                // {
                //     if (s[i] == s[nLeft])
                //     {
                //         nLeftCount++;
                //     }                    
                // }                
                // if (nLeftCount >= backups_map[s[nLeft]])
                // {
                //     nLeft++; 
                //     strRes = s.substr(nLeft, nRight-nLeft+1);
                //     continue;
                // }
                // else
                // {
                //     if (nRight + 1 >= s.size())
                //     {
                //         break;
                //     }
                //     t_map[s[nLeft]]++;
                //     nCount--;
                //     nLeft++;
                // }                                        
            }
            while (nLeft < s.size() && nRight+1 < s.size() && nCount < t.size())
            {
                if (t_map.find(s[nLeft]) != t_map.end())
                {
                    if (t_map[s[nLeft]] >= 0)
                    {
                        nCount--; 
                    }
                    t_map[s[nLeft]]++;
                }
                nLeft++;
                nRight++;
                if (t_map.find(s[nRight]) != t_map.end())
                {
                    if (t_map[s[nRight]] > 0)
                    {
                        nCount++;
                    }
                    t_map[s[nRight]]--;
                }
            }
            if (nCount == t.size())
            {
                strRes = s.substr(nLeft, nRight-nLeft+1);
                if (nRight-nLeft+1 == t.size())
                {
                    return strRes;
                }
            }
        }
        return strRes;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << sol.minWindow("ab", "a") << endl;
    cout << sol.minWindow("abc", "ab") << endl;
    cout << sol.minWindow("aa", "aa") << endl;
    cout << sol.minWindow("bba", "ab") << endl;
    cout << sol.minWindow("acbbaca", "aba") << endl;        
    _getch();
    return 0;
}

