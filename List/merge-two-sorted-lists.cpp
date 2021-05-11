/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include<conio.h>
#include<vector>
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
        {
            return l2;
        }
        ListNode* curL1 = l1;
        ListNode* curL2 = l2;
        ListNode* pre = nullptr;
        while (curL1 != nullptr && curL2 != nullptr)
        {
            if(curL1->val < curL2->val)
            {
                pre = curL1;
                curL1 = curL1->next;
            }
            else
            {
                if (pre == nullptr)
                {
                    l1 = curL2;
                    pre = curL2;
                    curL2 = curL2->next;
                    l1->next = curL1;
                }
                else
                {
                    pre->next = curL2;
                    curL2 = curL2->next;
                    pre->next->next = curL1;
                    pre = pre->next;                         
                }
            }
        }
        if (curL2 != nullptr)
        {
            pre->next = curL2;
        }
        return l1;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    int a[] = {5};
    int b[] = {1,2,4};
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
    for (int i = sizeof(a)/sizeof(int) - 1; i >= 0; i--)
    {
        l1 = new ListNode(a[i], l1);
    }
     for (int i = sizeof(b)/sizeof(int) - 1; i >= 0; i--)
    {
        l2 = new ListNode(b[i], l2);
    }   
    
    // ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    // ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    l1 = sol.mergeTwoLists(l1, l2);
    while (l1 != nullptr)
    {
        cout << l1->val << ", ";
        l1 = l1->next;
    }
    
    _getch();
    return 0;
}

