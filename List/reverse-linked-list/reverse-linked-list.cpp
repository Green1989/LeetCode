/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <stack>
#include <conio.h>
#include <iostream>
using namespace std;
// @lc code=start
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return NULL;
        }        
        stack<ListNode*> staListNode; 
        ListNode* pResultListNode = NULL;
        ListNode* pCurListNode = head;
        while (pCurListNode)
        {
            staListNode.push(pCurListNode);
            pCurListNode = pCurListNode->next;
        }        
        if (!staListNode.empty())
        {
            pResultListNode = staListNode.top();
            staListNode.pop();
            pCurListNode = pResultListNode;
        }
        while (!staListNode.empty())
        {
            pCurListNode->next = staListNode.top();
            pCurListNode = pCurListNode->next;     
            staListNode.pop();       
        }
        pCurListNode->next = NULL;   
        return pResultListNode;                                   
    }
    
};
int main()
{
    Solution sol;
    ListNode* pCurListNode = NULL;
    ListNode* pResListNode = NULL;
    for (int i = 0; i < 10; i++)
    {
        pCurListNode = new ListNode(i, pCurListNode);
    }
    ListNode* pPrintListNode = pCurListNode;
	while (pPrintListNode)
    {
        cout << pPrintListNode->val << "->";
        pPrintListNode = pPrintListNode->next;
    }
    cout << "NULL" << endl;    
	pResListNode = sol.reverseList(pCurListNode);
    pPrintListNode = pResListNode;
	while (pPrintListNode)
    {
        cout << pPrintListNode->val << "->";
        pPrintListNode = pPrintListNode->next;
    }
    cout << "NULL" << endl;    

	_getch();
	return 0;
}

// @lc code=end

