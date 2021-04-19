/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <conio.h>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> set1;
        unordered_set <int> set2;
        vector<int> vecIntersection;
        for (auto &&nums : nums1)
        {
            set1.insert(nums);            
        }
        for (auto &&nums : nums2)
        {
            set2.insert(nums);            
        }
        if(set1.size() < set2.size())
        {
            for (auto &&nums : set1)
            {
                if (set2.count(nums) > 0)
                {
                    vecIntersection.push_back(nums);
                }                                
            }            
        }
        else
        {
            for (auto &&nums : set2)
            {
                if (set1.count(nums) > 0)
                {
                    vecIntersection.push_back(nums);
                }                                
            }              
        }
        return vecIntersection;        
    }
};
int main()
{
    Solution sol;
    vector<int> vecResult;

	int nTemp1[] = {1,2,2,1};
	vector <int> vecNums1(nTemp1, nTemp1+4);
    int nTemp2[] = {2,2};
	vector <int> vecNums2(nTemp2, nTemp2+2);
    vecResult = sol.intersection(vecNums1, vecNums2);

    cout << "[";
    for (int i = 0; i < vecResult.size(); i++)
    {
        cout << vecResult[i] << ", ";
    }
    cout << "]" << endl;

    int nTemp3[] = {4,9,5};
	vector <int> vecNums3(nTemp3, nTemp3+3);
    int nTemp4[] = {9,4,9,8,4};
	vector <int> vecNums4(nTemp4, nTemp4+5);
    vecResult = sol.intersection(vecNums3, vecNums4);

    cout << "[";
    for (int i = 0; i < vecResult.size(); i++)
    {
        cout << vecResult[i] << ", ";
    }
    cout << "]" << endl;
    

	_getch();
	return 0;
}
// @lc code=end

