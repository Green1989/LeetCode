/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int nCount = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA != NULL && curB != NULL)
        {
            curA = curA->next;
            curB = curB->next;
        }
        if (curA == NULL)
        {
            while (curB != NULL)
            {
                curB = curB->next;
                nCount++;
            }
            curA = headA;
            curB = headB;
            while (nCount > 0)
            {
                curB = curB->next;
                nCount--;
            }
            while (curA != curB)
            {
                curA = curA->next;
                curB = curB->next;
            }      
        }
        else
        {
            while (curA != NULL)
            {
                curA = curA->next;
                nCount++;
            }
            curA = headA;
            curB = headB;
            while (nCount > 0)
            {
                curA = curA->next;
                nCount--;
            }
            while (curA != curB)
            {
                curA = curA->next;
                curB = curB->next;
            }
        }
        return curA;
    }
};
// @lc code=end

