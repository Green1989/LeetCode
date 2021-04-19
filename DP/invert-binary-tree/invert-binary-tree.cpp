// invert-binary-tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(NULL), right(NULL) {}
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* invertTree(TreeNode* root) {

	if (root == NULL)
	{
		return root;
	}
	swap(root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);
}
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode stuTreeNodeLeft11(1);
	TreeNode stuTreeNodeLeft12(3);
	TreeNode stuTreeNodeLeft1(2, &stuTreeNodeLeft11, &stuTreeNodeLeft12);

	TreeNode stuTreeNodeRight11(6);
	TreeNode stuTreeNodeRight12(9);
	TreeNode stuTreeNodeRight1(7, &stuTreeNodeRight11, &stuTreeNodeRight12);

	TreeNode stuTreeNodeRoot(4, &stuTreeNodeLeft1, &stuTreeNodeRight1);

	TreeNode * pNewTreeNode = invertTree(&stuTreeNodeRoot);
	_getch();
	return 0;
}

