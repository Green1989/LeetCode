/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        bool bExistZero = false;
        int i = 0;
        for (; i < A.size(); i++)
        {
            if (A[i] >= 0 || K <= 0)
            {
                if (A[i] == 0)
                {
                    bExistZero = true;
                }                
                break;
            }
            K--;
            A[i] *= (-1);
        }
        if (K > 0 && K%2!=0 && !bExistZero)
        {
            if (i <= 0)
            {
                A[0] *= (-1);
            }
            else if (i >= A.size())
            {
                A[A.size()-1] *= (-1);
            }
            else
            {
                if (A[i] < A[i-1])
                {
                    A[i] *= (-1);
                }
                else
                {
                    A[i-1] *= (-1);                    
                }
            }
        }
        int nSum = 0;
        for (auto &&n : A)
        {
            nSum += n;
        }
        return nSum;  
    }
};
// @lc code=end

