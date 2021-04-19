/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <iostream>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        TreeNode* pNewRoot = reverseTree(root);
        return isSameTree(root, pNewRoot);        
    }
    TreeNode* reverseTree(TreeNode* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        TreeNode* pNewRoot = new TreeNode(root->val, root->left, root->right);
        swap(pNewRoot->left, pNewRoot->right);
        reverseTree(pNewRoot->left);
        reverseTree(pNewRoot->right);        
        return pNewRoot;
    }
    bool isSameTree(TreeNode* root1, TreeNode *root2)
    {
        bool bRet = true;;
        if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
        {
            return false;
        }
        else if ((root1->left != NULL && root2->left == NULL) || (root1->left == NULL && root2->left != NULL))
        {
            return false;
        }
        else if ((root1->right != NULL && root2->right == NULL) || (root1->right == NULL && root2->right != NULL))
        {
            return false;
        }
        else if (root1 != NULL && root2 != NULL)
        {
            bRet = bRet && (root1->val == root2->val);
        }

        if (root1->left != NULL && root2->left != NULL)
        {
            bRet = bRet && isSameTree(root1->left, root2->left);
        }
        if (root1->right != NULL && root2->right != NULL)
        {
            bRet = bRet && isSameTree(root1->right, root2->right);
        }
        return bRet;
    }
};
// @lc code=end

