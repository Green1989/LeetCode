/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int nOffset = 0;
        int nResult = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* lastCur = l1;    
        while (cur1 != nullptr && cur2 != nullptr)
        {
            nResult = (cur1->val + cur2->val + nOffset)%10;
            nOffset = (cur1->val + cur2->val + nOffset)/10;
            cur1->val = nResult;
            cur2->val = cur1->val;
            lastCur = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        if (cur1 != nullptr)
        {
            while (cur1 != nullptr && nOffset > 0)
            {
                nResult = (cur1->val + nOffset)%10;
                nOffset = (cur1->val + nOffset)/10;
                lastCur = cur1;
                cur1->val = nResult;   
                cur1 = cur1->next;         
            }
            if (cur1 == nullptr && nOffset > 0)
            {
                lastCur->next = new ListNode(nOffset);
            }            
            return l1;
        }
        else if (cur2 != nullptr)
        {
            while (cur2 != nullptr && nOffset > 0)
            {
                nResult = (cur2->val + nOffset)%10;
                nOffset = (cur2->val + nOffset)/10;
                lastCur = cur2;
                cur2->val = nResult;   
                cur2 = cur2->next;         
            }
            if (cur2 == nullptr && nOffset > 0)
            {
                lastCur->next = new ListNode(nOffset);
            }      
            return l2;
        }
        else
        {
            if (nOffset > 0)
            {
                lastCur->next = new ListNode(nOffset);                
            }
            return l1;            
        }
    }
};
// @lc code=end

