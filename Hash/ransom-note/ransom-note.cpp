/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <conio.h>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int nArray[26] = {0};
        int nMagazineLen = magazine.length();
        int nRansomNoteLen = ransomNote.length();
        for (int i = 0; i < nMagazineLen; i++)
        {
            nArray[magazine[i] - 'a']++;
        }
        for (int i = 0; i < nRansomNoteLen; i++)
        {
            if ((--nArray[ransomNote[i] - 'a']) < 0)
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
    string ransomNote = "aa";
    string magazine = "aab";
    bool bRet = sol.canConstruct(ransomNote, magazine);

    cout << bRet << endl;  

	_getch();
	return 0;
}
// @lc code=end

