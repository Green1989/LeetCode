// remove-linked-list-elements.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
//#include <numeric>
using namespace std;
/**
* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};1

ListNode* removeElements(ListNode* head, int val) {
	while (head->val == val)
	{
		head = head->next;
	}
	ListNode * pPreNode = head;
	ListNode * pCurNode = head->next;
	while (pCurNode != NULL)
	{
		if (pCurNode->val == val)//ɾ����ǰ�ڵ�
		{
			pCurNode = pCurNode->next;
			pPreNode->next = pCurNode;
		}
		else
		{
			pPreNode = pCurNode;
			pCurNode = pCurNode->next;
		}
	}
	return head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	_getch();
	return 0;
}

