/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */
#include <conio.h>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i] ) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);        
    }
};
// int main()
// {
//     Solution sol;
//     int nRet = sol.monotoneIncreasingDigits(10);
//     cout << nRet << endl;
//     nRet = sol.monotoneIncreasingDigits(1234);
//     cout << nRet << endl;
//     nRet = sol.monotoneIncreasingDigits(332);
//     cout << nRet << endl;
    
// 	_getch();
// 	return 0;
// }
// @lc code=end

