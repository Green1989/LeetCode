/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include<conio.h>
#include<set>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // multiset<int> st(nums1.begin(), nums1.end());
        // for (auto &&n : nums2)
        // {
        //     st.insert(n);
        // }
        // if (st.size() % 2 == 0)
        // {
        //     int nCount = 0;
        //     for (multiset<int>::iterator p = st.begin(); p != st.end(); p++)
        //     {
        //         if (nCount == st.size()/2-1)
        //         {
        //             double nResult = *p;
        //             p++;
        //             nResult += *p;
        //             return nResult/2;
        //         }                
        //         nCount++;
        //     }
        // }
        // else
        // {
        //     int nCount = 0;
        //     for (multiset<int>::iterator p = st.begin(); p != st.end(); p++)
        //     {
        //         if (nCount == st.size()/2)
        //         {
        //             return *p;
        //         }
        //         nCount++;
        //     }            
        // }
        //return 0;          
        int nSize = nums1.size() + nums2.size();
        if (nSize == 1)
        {
            if (nums1.size() > 0)
            {
                return nums1[0];
            }
            else
            {
                return nums2[0];
            }            
        }
        
        int nTarget = nSize/2;
        int nIndex1 = 0;
        int nIndex2 = 0;
        while (nIndex1 + nIndex2 < nTarget-1)
        {
            if (nIndex2 >= nums2.size() || (nIndex1 < nums1.size() && nums1[nIndex1] < nums2[nIndex2]))
            {
                nIndex1++;
            }
            else
            {
                nIndex2++;
            }
        }
        if (nSize % 2 == 0)
        {
            double dResult = 0;
            if (nIndex2 >= nums2.size() || (nIndex1 < nums1.size() && nums1[nIndex1] < nums2[nIndex2]))
            {
                dResult += nums1[nIndex1];
                nIndex1++;
            }
            else
            {
                dResult += nums2[nIndex2];
                nIndex2++;
            }
            if (nIndex2 >= nums2.size() || (nIndex1 < nums1.size() && nums1[nIndex1] < nums2[nIndex2]))
            {
                dResult += nums1[nIndex1];
                nIndex1++;
            }
            else
            {
                dResult += nums2[nIndex2];
                nIndex2++;
            }       
            return dResult/2;     
        }
        else
        {
            if (nIndex2 >= nums2.size() || (nIndex1 < nums1.size() && nums1[nIndex1] < nums2[nIndex2]))
            {
                nIndex1++;
            }
            else
            {
                nIndex2++;
            }
            if (nIndex2 >= nums2.size() || (nIndex1 < nums1.size() && nums1[nIndex1] < nums2[nIndex2]))
            {
                return nums1[nIndex1];
            }
            else
            {
                return nums2[nIndex2];
            }             
        }
        return 0;              
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    //string sTest = "ohomm";
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    _getch();
    return 0;
}
