/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
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
    bool hasCycle(ListNode *head) {
        while (head)
        {
            if(head->val <= 100000)
            {
                head->val = 100001;
            }
            else
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};
int main()
{
    Solution sol;
    ListNode* pCurListNode = NULL;
    ListNode* pResListNode = NULL;

	bool bRet = sol.hasCycle(pCurListNode);

    cout << bRet << endl;

	_getch();
	return 0;
}

// @lc code=end

