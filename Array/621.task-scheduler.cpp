/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include<conio.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<char> vecPrint;
    static bool cmp(vector<char>&a, vector<char>&b)
    {
        return a.size() > b.size(); 
    }
        
    int leastInterval(vector<char>& tasks, int n) {
        sort(tasks.begin(), tasks.end());
        vector<vector<char>> vecAllTasks;
        vector<char> vecTasks;
        vecTasks.emplace_back(tasks[0]);
        for (int i = 1; i < tasks.size(); i++)
        {
            if (tasks[i] != tasks[i-1])
            {
                vecAllTasks.emplace_back(vecTasks);
                vecTasks.clear();
                vecTasks.emplace_back(tasks[i]);
            }
            else
            {
                vecTasks.emplace_back(tasks[i]);
            }
        }
        vecAllTasks.emplace_back(vecTasks);
        sort(vecAllTasks.begin(), vecAllTasks.end(), cmp);
        int nCount = 0;
        int nStep = 0;
        
        while (!vecAllTasks.empty())
        {
            vector<vector<char>>::iterator itr = vecAllTasks.begin();
            while (itr != vecAllTasks.end())
            {
                vecPrint.emplace_back(itr->back());
                itr->pop_back();
                nStep++;
                nCount++;
                if (itr->empty())
                {
                    itr = vecAllTasks.erase(itr);
                }
                else
                {
                    itr++;
                }
                if (nStep == n+1)
                {
                    sort(vecAllTasks.begin(), vecAllTasks.end(), cmp);
                    itr = vecAllTasks.begin();
                    nStep = 0;
                }                
            }
            if (vecAllTasks.empty())
            {
                break;
            }            
            while (nStep < n + 1)
            {
                vecPrint.emplace_back('*');
                nStep++;
                nCount++;                
            }
            nStep = 0;
        }
        return nCount;        
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    int n = 2;
    cout << sol.leastInterval(tasks, n) << endl;
    for (auto &&c : sol.vecPrint)
    {
        cout << c << ", ";
    }
    
    _getch();
    return 0;
}


