/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include<conio.h>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string strRes;
        string strTemp;
        int nIndex = 0;
        while (nIndex < s.size())
        {
            if (s[nIndex] >= 'a' && s[nIndex] <= 'z')
            {
                strRes.push_back(s[nIndex]);
                nIndex++;
            }
            else if (s[nIndex] >= '0' && s[nIndex] <= '9')
            {
                strRes += DFS(s, nIndex);
            }
        }
        return strRes;        
    }
    string DFS(string s, int& nCur)
    {
        string strRes;
        string strChild;
        string strNum;
        int nCount = 0;
        int nIndex = nCur;
        while (s[nIndex] != '[')
        {
            strNum.push_back(s[nIndex]);
            nIndex++;
        }
        int nNum = atoi(strNum.c_str());
        nIndex++;
        strChild.clear();
        while (s[nIndex] != ']')
        {
            if (s[nIndex] >= 'a' && s[nIndex] <= 'z')
            {
                strChild.push_back(s[nIndex]);
                nIndex++;
            }
            else if (s[nIndex] >= '0' && s[nIndex] <= '9')
            {
                strChild += DFS(s, nIndex);
            }
        }
        for (int i = 0; i < nNum; i++)
        {
            strRes += strChild;
        }
        nCur = nIndex + 1;
        return strRes;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    cout << sol.decodeString("3[a]2[bc]") << endl;
    cout << sol.decodeString("3[a2[c]]") << endl;
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;
    cout << sol.decodeString("abc3[cd]xyz") << endl;
    _getch();
    return 0;
}

