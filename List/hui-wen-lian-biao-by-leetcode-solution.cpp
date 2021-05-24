/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
#include<conio.h>
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && slow->next != nullptr)
        {
            fast = fast->next;
            if (fast->next == nullptr)
            {
                break;
            }
            fast = fast->next;
            slow = slow->next;            
        }
        fast = reverseList(slow->next);
        slow->next = nullptr;
        slow = head;
        while (fast != nullptr && slow != nullptr)
        {
            if (fast->val != slow->val)
            {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* root)
    {
        ListNode* cur = root;
        ListNode* curNext = root->next;
        
        while(curNext != nullptr)
        {
            ListNode* temp = curNext->next;
            curNext->next = cur;
            if (temp != nullptr)
            {
                ListNode* tempNext = temp->next;                
                temp->next = curNext;
                curNext = tempNext;
                cur = temp; 
            }
            else
            {
                cur = curNext;
                curNext = nullptr;
            }
        }
        root->next = nullptr;
        return cur;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    int a[] = {8,0,7,1,7,7,9,7,5,2,9,1,7,3,7,0,6,5,1,7,7,9,3,8,1,5,7,7,8,4,0,9,3,7,3,4,5,7,4,8,8,5,8,9,8,5,8,8,4,7,5,4,3,7,3,9,0,4,8,7,7,5,1,8,3,9,7,7,1,5,6,0,7,3,7,1,9,2,5,7,9,7,7,1,7,0,8};
    ////int a[] = {1, 2, 3, 1};
    ListNode* head = nullptr;
    for (int i = sizeof(a)/sizeof(int) - 1; i >= 0; i--)
    {
        head = new ListNode(a[i], head);
    }
    cout << sol.isPalindrome(head);
    
    _getch();
    return 0;
}
