/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <conio.h>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.empty())
        {
            return s;
        }
        int nIndex = 0;
        int nStart, nEnd;
        while (nIndex<s.length())
        {
            int nReverLen = k<(s.length()-nIndex)?k:(s.length()-nIndex);
            nStart = nIndex;
            nEnd = nIndex+nReverLen-1;
            while (nStart < nEnd)            
            {
                s[nStart] ^= s[nEnd];
                s[nEnd] ^= s[nStart];
                s[nStart] ^= s[nEnd];
                nStart++;
                nEnd--;
            }
            nIndex = nIndex + nReverLen + nReverLen;
        }
        return s;
    }
};
int main()
{
    Solution sol;
    string s = "abcdefg";
    string strRet = sol.reverseStr(s, 2);

    cout << strRet << endl;  

	_getch();
	return 0;
}
// @lc code=end

