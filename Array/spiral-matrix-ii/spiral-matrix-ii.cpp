/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>
#include <conio.h>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vecResult(n, vector<int>(n, 0));
        int nTop = 0;
        int nBottom = n-1;
        int nLeft = 0;
        int nRight = n-1;
        int nCount = 0;
        int nMaxCount = n*n;
        while (nCount < nMaxCount)
        {
            for (int i = nLeft, j = nTop; i <= nRight; i++)
            {
                vecResult[j][i] = ++nCount;
            }
            for (int i = nTop+1, j = nRight; i <= nBottom; i++)
            {
                vecResult[i][j] = ++nCount;
            }
            for (int i = nRight-1, j = nBottom; i >= nLeft; i--)
            {
                vecResult[j][i] = ++nCount;
            }
            for (int i = nBottom-1, j = nLeft; i > nTop; i--)
            {
                vecResult[i][j] = ++nCount;
            }
            nTop++;
            nBottom--;
            nLeft++;
            nRight--;            
        }
        return vecResult;        
    }
};
int main()
{
    Solution sol;
	vector <vector <int>> nums;
	int target = 3;
    for (int k = 0; k < 5; k++)
    {
        nums = sol.generateMatrix(k);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[0].size(); j++)
            {
                cout << nums[i][j] << ", ";
            }
            cout << endl;        
        }
    }
	_getch();
	return 0;
}
// @lc code=end

