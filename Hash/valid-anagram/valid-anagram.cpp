/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <conio.h>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int nArray[26] = {0};
        int sLen = s.length();
        int tLen = t.length();
        if (sLen != tLen)
        {
            return false;
        }        
        for (int i = 0; i < sLen; i++)
        {
            nArray[s[i] - 'a']++;
        }
        for (int i = 0; i < tLen; i++)
        {
            if((--nArray[t[i] - 'a']) < 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    cout << sol.isAnagram(s, t) << endl;

    string s1 = "rat";
    string t1 = "car";
	cout << sol.isAnagram(s1, t1) << endl;

	_getch();
	return 0;
}
// @lc code=end

