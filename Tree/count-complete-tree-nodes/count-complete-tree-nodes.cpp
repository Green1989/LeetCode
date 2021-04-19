#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <queue>
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
int getCBTreesNodes(TreeNode* pCurNode)
{
	if (pCurNode == NULL)
		return 0;
	int nLeftNodes = getCBTreesNodes(pCurNode->left);
	int nRightNodes = getCBTreesNodes(pCurNode->right);
	return nLeftNodes + nRightNodes + 1;
}
int countNodes(TreeNode* root) {
	return getCBTreesNodes(root);
}

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


TreeNode* creCBiTree(int *p,int num)
{	
	if (p==NULL||num<=0)
	{
		return NULL;
	}
	TreeNode *head=new TreeNode;
	head->val=p[0];
	creBiTreeNode(p, num, head, 0);
	return head;
}
