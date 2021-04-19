// minimum-depth-of-binary-tree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <queue>
//#include <numeric>
using namespace std;
/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void creBiTreeNode(int *p,int num,TreeNode *cur,int curIndex);

TreeNode* creBiTree(int *p,int num);

int getDepth(TreeNode* node) 
{
	if (node == NULL) 
		return 0;
	int leftDepth = getDepth(node->left);
	int rightDepth = getDepth(node->right);
	if (node->left == NULL && node->right != NULL) 
	{ 
		return 1 + rightDepth;
	}
	if (node->left != NULL && node->right == NULL) 
	{ 
		return 1 + leftDepth;
	}
	int result = 1 + min(leftDepth, rightDepth); 
	return result;
}

int minDepth(TreeNode* root) {
	return getDepth(root);
}
int _tmain(int argc, _TCHAR* argv[])
{
	//int nTemp[] = {3,9,20,NULL,NULL,15,7};
	//int nTemp[] = {2,NULL,3,NULL,4,NULL,5,NULL,6};
	int nTemp[] = {1,NULL,2,4,3,NULL,NULL,6,5};

	TreeNode* root = creBiTree(nTemp, sizeof(nTemp)/sizeof(int));
	int nRet = minDepth(root);
	cout << endl << nRet << endl;
	_getch();
	return 0;
}

// int creCompleteBTreeNum(int *pIn, int *pOut)
// {
// 	int size = sizeof(pIn)/sizeof(int);
// 	int *nStep = new int[size];
// 	int index = 0;
// 	for (int i=0;i<size;i++)
// 		nStep[i] = 1;
// 	for (int i=0;i<size;i++)
// 	{
// 		pOut[index] = pIn[i];
// 		if (pIn[i] == NULL)
// 		{
// 			pOut[2*index+1] = NULL;
// 			pOut[2*index+2] = NULL;
// 			nStep[2*index] = 3;			
// 		}
// 		index += nStep[i];
// 	}
// 	return index;
// }

/*
void creBiTreeNode(int *p,int num,TreeNode *cur,int curIndex)
{
	if (p==NULL||num<=0||cur==NULL||curIndex>=num||curIndex<0)
	{
		return ;
	}
	int last=num-1;
	if (2*curIndex+1<=last)
	{
		if (p[2*curIndex+1] != NULL)
		{
			cur->left=new TreeNode(p[2*curIndex+1]);
			//cur->left->val=p[2*curIndex+1];
		}
	}
// 	else
// 	{
// 		cur->left=NULL;	
// 	}
	if (2*curIndex+2<=last)
	{
		if (p[2*curIndex+1] != NULL)
		{
			cur->right=new TreeNode(p[2*curIndex+2]);
			//cur->right->val=p[2*curIndex+2];
		}
	}
// 	else
// 	{
// 		cur->right=NULL;
// 	}
	creBiTreeNode(p, num, cur->left, 2*curIndex+1);
	creBiTreeNode(p, num, cur->right, 2*curIndex+2);
}
*/

TreeNode* creBiTree(int *p,int num)
{	
	if (p==NULL||num<=0)
	{
		return NULL;
	}
	TreeNode *head=new TreeNode;
	head->val=p[0];

	queue<TreeNode*> que;
	if (head != NULL) que.push(head);
	TreeNode *LchildNode=NULL;
	TreeNode *RchildNode=NULL;
	int index = 0;
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++) 
		{
			TreeNode* node = que.front();
			que.pop();
			if (index < num)
			{
				node->val = p[index];
				if (node->val != NULL)
				{
					LchildNode=new TreeNode;
					que.push(LchildNode);
					RchildNode=new TreeNode;
					que.push(RchildNode);
					node->left = LchildNode;
					node->right = RchildNode;
				}
				index++;
			}
		}
	}

	if (head != NULL) que.push(head);
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++) 
		{
			TreeNode* node = que.front();
			que.pop();
			if (node->left->val == NULL)
			{
				delete node->left;
				node->left = NULL;
			}
			else
			{
				que.push(node->left);
			}
			if (node->right->val == NULL)
			{
				delete node->right;
				node->right = NULL;
			}
			else
			{
				que.push(node->right);
			}
		}
	}

	return head;
}

