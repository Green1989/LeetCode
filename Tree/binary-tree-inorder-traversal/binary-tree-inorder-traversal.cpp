/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

#include <conio.h>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 *  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
        vecNode.push_back(root->val);
        BitTreeTraversal(root->right, vecNode);        
    }  
};
// @lc code=end

