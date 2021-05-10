/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<set>
#include<unordered_map>
#include<conio.h>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {      
        unordered_map<char, int> map;
        int nMaxSize = 0;
        int nStart = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (map.find(s[i]) != map.end() && map[s[i]] >= nStart)
            {                
                nStart = map[s[i]];                             
            }
            nMaxSize = nMaxSize>(i-nStart)? nMaxSize:(i-nStart);   
            map[s[i]] = i;
        }        
        return nMaxSize;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    string sTest = "kubdypzxdivrqa";
    //string sTest = "ohomm";
    cout << sol.lengthOfLongestSubstring(sTest) << endl;
    _getch();
    return 0;
}
