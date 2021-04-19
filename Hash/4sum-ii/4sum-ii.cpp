/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <conio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map <int, int> ab_map;
        for (auto &&a : A)
        {
            for (auto &&b : B)
            {
                ab_map[a+b]++;
            }            
        }
        int nCount = 0;
        for (auto &&c : C)
        {
            for (auto &&d : D)
            {
                if(ab_map.find(-1*(c+d)) != ab_map.end())
                {
                    nCount += ab_map[-1*(c+d)];
                }
            }            
        }                
        return nCount;
    }
};
int main()
{
    Solution sol;
    vector<int> vecResult;

	vector <int> vecNums1 = {1, 2};
	vector <int> vecNums2 = {-2,-1};
    vector <int> vecNums3 = {-1, 2};
	vector <int> vecNums4 = {0, 2};
    int nRet = sol.fourSumCount(vecNums1, vecNums2, vecNums3, vecNums4);

    cout << nRet << endl;
   

	_getch();
	return 0;
}

// @lc code=end

