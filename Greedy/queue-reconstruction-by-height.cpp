/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include <conio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[0] == b[0])
        {
            return a[1] < b[1];
        }
        else
        {
            return a[0] < b[0];
        }
    }    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> vecResult(people.begin(), people.end());
        sort(vecResult.begin(), vecResult.end(), cmp);
        int k = 0;
        for (int i = vecResult.size() - 1; i >= 0 ; i--)
        {
            if (vecResult[i][1] == 0)
            {
                continue;
            }
            int nCount = 0;
            for (int j = 0; j < vecResult.size(); j++)
            {
                if (vecResult[j][0] >= vecResult[i][0] && j != i)
                {
                    nCount++;
                    if (nCount == vecResult[i][1])
                    {
                        if(j+1 < i)
                        {
                            vecResult.insert(vecResult.begin()+j+1, vecResult[i]);
                            vecResult.erase(vecResult.begin()+i+1);                    
                        }
                        else if (j+1 > i)
                        {
                            vecResult.insert(vecResult.begin()+j+1, vecResult[i]);
                            vecResult.erase(vecResult.begin()+i); 
                        }                        
                    }   
                }                             
            }                                    
        }        
        return vecResult;
    }
};
// int main()
// {
//     Solution sol;
//     vector<vector<int>> people = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
//     vector<vector<int>> vecResult;
//     vecResult = sol.reconstructQueue(people);
//     for (int i = 0; i < vecResult.size(); i++)
//     {
//         if (i == 0)
//         {
//             cout << "[";
//         }        
//         for (int j = 0; j < vecResult[i].size(); j++)
//         {
//             if (j == 0)
//             {
//                 cout << "[";
//             }
//             cout << vecResult[i][j]; 
//             if(j == vecResult[i].size() - 1)
//             {
//                 cout << "]";
//             }
//             else
//             {
//                 cout << ",";                
//             }
//         }
//         if(i == vecResult.size() - 1)
//         {
//             cout << "]";
//         }
//         else
//         {
//             cout << ",";                
//         }
//     }
// 	_getch();
// 	return 0;
// }

// @lc code=end

