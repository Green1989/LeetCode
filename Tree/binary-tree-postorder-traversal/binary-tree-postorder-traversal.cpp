/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vecRes;
        BitTreeTraversal(root, vecRes);
        return vecRes;     
    }
    void BitTreeTraversal(TreeNode* root, vector<int> &vecNode)
    {
        if(root == NULL)
        {
            return ;
        }
        BitTreeTraversal(root->left, vecNode);        
        BitTreeTraversal(root->right, vecNode);     
        vecNode.push_back(root->val);   
    }  
};
// @lc code=end

