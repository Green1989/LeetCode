/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        else if (lists.size() == 1)
        {
            return lists[0];
        }
        ListNode* root = getListsMinNode(lists);
        ListNode* cur = root;
        while (cur)
        {
            cur->next = getListsMinNode(lists);
            cur = cur->next;
        }      
        return root;
    }
    ListNode* getListsMinNode(vector<ListNode*>& lists)
    {
        int nMinListIndex = -1;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
            {
                if (nMinListIndex < 0)
                {
                    nMinListIndex = i;
                    continue;
                }
                if (lists[nMinListIndex]->val > lists[i]->val)
                {
                    nMinListIndex = i;
                }                
            }
        }
        if (nMinListIndex < 0)
        {
            return nullptr;
        }
        ListNode* minListNode = lists[nMinListIndex];
        lists[nMinListIndex] = lists[nMinListIndex]->next;
        return minListNode;
    }
};
// @lc code=end

