/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }        
        ListNode* left = head;
        ListNode* right = head;
        ListNode* rightTail;

        rightTail = GetMinVaulePreNode(head);
        left = rightTail->next;
        rightTail->next = nullptr;
        ListNode* cur = left;
        ListNode* begin = right;
        ListNode* endPre = right;
        ListNode* end = right;
        while (cur->next != nullptr)
        {
            if(cur->next->val > begin->val)
            {                
                end = begin->next;
                while (cur->next->val > end->val)
                {
                    endPre = end;
                    end = end->next;
                }                
            }
        }
        

    }
    ListNode* GetMinVaulePreNode(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* curPre = nullptr;
        ListNode* MinValueNode = head;
        ListNode* MinValuePreNode = nullptr;
        while (cur->next != nullptr)
        {
            if(cur->val > cur->next->val)
            {
                swap(cur->val, cur->next->val);
            }
            if (MinValueNode->val > cur->val)
            {
                MinValueNode = cur;
                MinValuePreNode = curPre;
            }
            curPre = cur;
            cur = cur->next;
        }
        if (MinValueNode->val > cur->val)
        {
            MinValueNode = cur;
            MinValuePreNode = curPre;
        }
        return MinValuePreNode;
    }
};
// @lc code=end

