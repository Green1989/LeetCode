/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <conio.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
// @lc code=start
class MyQueue
{
private:
    deque <int> m_que;
public:
    void pop(int nValue)
    {
        if(!m_que.empty() && nValue == m_que.front())
        {
            m_que.pop_front();
        }
    }
    void push(int nValue)
    {
        while (!m_que.empty()  && nValue > m_que.back())
        {
            m_que.pop_back();            
        }
        m_que.push_back(nValue);
    }
    int front()
    {
        return m_que.front();
    }

};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vecRes;
        MyQueue myQ;
        for (int i = 0; i < nums.size(); i++)
        {
            myQ.push(nums[i]);
            if (i >= k-1)
            {
                vecRes.push_back(myQ.front());
                myQ.pop(nums[i-(k-1)]);
            }
        }        
        return vecRes;
    }
};
// int main()
// {
//     Solution sol;
//     vector<int> nums = {1,3,-1,-3,5,3,6,7};
//     vector<int> vecRes = sol.maxSlidingWindow(nums, 3);
//     for (auto &&n : nums)
//     {
//         cout << n << ", ";
//     }  
//     cout << endl;
//     for (auto &&n : vecRes)
//     {
//         cout << n << ", ";
//     }  
//     cout << endl;
//     _getch();
//     return 0;
// }
// @lc code=end

