/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include<algorithm>
#include<conio.h>
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {        
        vector<vector<string>> vecResult;
        unordered_map<string, vector<string>> mapAnagrams;
        for (auto &&s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mapAnagrams[key].emplace_back(s);
        }
        for(auto it = mapAnagrams.begin(); it != mapAnagrams.end(); it++)
        {
            vecResult.emplace_back(it->second);
        }
        return vecResult;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<string> strs{"hhhhu","tttti","tttit","hhhuh","hhuhh","tittt"};
    vector<vector<string>> vecResult;
    vecResult = sol.groupAnagrams(strs);
    for (int i = 0; i < vecResult.size(); i++)
    {
        for (int j = 0; j < vecResult[i].size(); j++)
        {
            cout << vecResult[i][j] << ", ";
        }
        cout << endl;
    }
    
    _getch();
    return 0;
}
