/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

#include <conio.h>
#include <iostream>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode* pFast = head->next;
        ListNode* pSlow = head;
        while (pFast != NULL && pFast->next != NULL)
        {
            if(pFast == pSlow)
            {
                pSlow = pSlow->next;
                ListNode* pSlowSeconde = head;
                while (pSlowSeconde != pSlow)
                {
                    pSlowSeconde = pSlowSeconde->next;
                    pSlow = pSlow->next;
                }
                return pSlowSeconde;                
            }
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        return NULL;
    }
};
int main()
{
    Solution sol;
    ListNode* pCurListNode = NULL;
    ListNode* pResListNode = NULL;

	pResListNode = sol.detectCycle(pCurListNode);

    cout << pResListNode->val << endl;

	_getch();
	return 0;
}
// @lc code=end

