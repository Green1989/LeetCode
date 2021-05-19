/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
#include <conio.h>
#include<vector>
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
    void flatten(TreeNode* root) {
        if (root == nullptr)
        {
            return;
        }
        FlattenChiled(root);        
    }
    TreeNode* FlattenChiled(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode* lastLeftNode = root;
        while (root->left == nullptr)
        {
            if (root->right == nullptr)
            {
                return lastLeftNode;
            }
            root = root->right;
        }
        TreeNode* leftTemp = FlattenChiled(root->left);
        TreeNode* rightTemp = root->right;       
        if (leftTemp != nullptr)
        {
            root->left = nullptr;
            root->right = leftTemp;
            while (leftTemp->right != nullptr)
            {
                leftTemp = leftTemp->right;
            }
            leftTemp->right = rightTemp;
        }
        FlattenChiled(rightTemp);
        return lastLeftNode;
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
    //int nTemp[] = {1,2,5,3,4,INT_MAX,6,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    //int nTemp[] = {1,2,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX};
    //int nTemp[] = {2,1,4,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX,INT_MAX};
    int nTemp[] = {4,1,INT_MAX,INT_MAX,3,2,INT_MAX};
    TreeNode* root = creCBiTree(nTemp, sizeof(nTemp)/sizeof(int));
    sol.flatten(root);
    _getch();
    return 0;
}