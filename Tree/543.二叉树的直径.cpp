/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
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

    }
    int traveral(TreeNode* root, int& nLeft, int& nRight)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }
        // int nLeft = 0;
        // int nRight = 0;
        if (root->left != nullptr)
        {
            nLeft = 1 + traveral(root->left, );
        }
        if (root->right != nullptr)
        {
            nRight = 1 + traveral(root->right);
        }
        
        
    }
};
// @lc code=end

