/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include <conio.h>
#include<queue>
#include<iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int nMaxDepth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            nMaxDepth++;
            int nSize = que.size();
            for(int i = 0; i < nSize; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left != nullptr)
                {
                    que.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    que.push(cur->right);
                }
            }
        }
        return nMaxDepth;
    }
};
// @lc code=end

TreeNode* creCBiTree(int *p,int num)
{	
	if (p==NULL||num<=0)
	{
		return NULL;
	}
    TreeNode *leftNode = NULL;
    TreeNode *rightNode = NULL;
	TreeNode *root=new TreeNode(p[0]);
    queue<TreeNode*> que;
    que.push(root);
    int nIndex = 1;
    while (!que.empty() && nIndex < num)
    {
        int nSize = que.size();
        for (int i = 0; i < nSize; i++)
        {
            TreeNode* curTreeNode = que.front();
            que.pop();
            if (p[nIndex] != INT_MAX)
            {
                leftNode = new TreeNode(p[nIndex]);
                curTreeNode->left = leftNode;
                que.push(leftNode);
            }
            nIndex++;
            if (p[nIndex] != INT_MAX)
            {
                rightNode = new TreeNode(p[nIndex]);
                curTreeNode->right = rightNode;
                que.push(rightNode);
            }
            nIndex++;
        }       
    }
    
	return root;
}

int main()
{
    Solution sol;
	int nTemp[] = {1,2,3,4,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    //int nTemp[] = {1,4,2,INT_MAX,INT_MAX,INT_MAX,3};
	//int nTemp[] = {2,NULL,3,NULL,4,NULL,5,c,6};

	TreeNode* root = creCBiTree(nTemp, sizeof(nTemp)/sizeof(int));
    int nRet = sol.maxDepth(root);
    cout << nRet << endl;
    _getch();
    return 0;
}