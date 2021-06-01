/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
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
    int nMax = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int nLeft = diameterOfBinaryTree(root->left);
        int nRight = diameterOfBinaryTree(root->right);
        int nMid = traveral(root->left) + traveral(root->right);
        return max(nMid, max(nLeft, nRight));
    }
    int traveral(TreeNode* root)
    {
        //if (root->left == nullptr && root->right == nullptr)
        if (root == nullptr)
        {
            return 0;
        }
        int nLeft = 1;
        int nRight = 1;
        if (root->left != nullptr)
        {
            nLeft += traveral(root->left);
        }
        if (root->right != nullptr)
        {
            nRight += traveral(root->right);
        }
        return max(nLeft, nRight);
    }
    
};
// @lc code=end

