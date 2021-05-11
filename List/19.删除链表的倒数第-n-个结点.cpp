/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* sel = head;
        int nCount = 0;
        while (cur->next != nullptr)
        {
            cur = cur->next;            
            if(nCount >= n)
            {
                sel = sel->next;
            }
            nCount++;
        }
        if (nCount == n-1)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;            
        }        
        else if (sel->next != nullptr)
        {
            ListNode* temp = sel->next;
            sel->next = sel->next->next;
            delete temp;
            return head;
        }
        else
        {
            return nullptr;
        }        
    }
};
// @lc code=end

