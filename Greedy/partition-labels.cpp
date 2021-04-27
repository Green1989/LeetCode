/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> vecResult;
        int nEnd = 0;
        for (int i = 0; i < S.length(); i++)
        {
            nEnd = i;
            for (int k = i; k <= nEnd; k++)            
            {
                for (int j = i+1; j < S.length(); j++)
                {
                    if (S[k] == S[j])
                    {
                        nEnd = nEnd>j? nEnd:j;
                    }
                }
            }
            vecResult.push_back(nEnd+1-i);
            i = nEnd;
                     
        }
        return vecResult;
    }
};
// int main()
// {
//     Solution sol;
//     vector<int> vecResult;
//     vecResult = sol.partitionLabels("ababcbacadefegdehijhklij");
//     for (int i = 0; i < vecResult.size(); i++)
//     {
//         cout << vecResult[i] << ", ";
//     }
    
// 	_getch();
// 	return 0;
// }
// @lc code=end

