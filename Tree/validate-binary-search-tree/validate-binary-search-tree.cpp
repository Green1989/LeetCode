/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include <queue>
#include <conio.h>
#include<iostream>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.*/
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
    long m_nMaxValue = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }        
        bool bLeft = isValidBST(root->left);
        if (m_nMaxValue < root->val)
        {
            m_nMaxValue = root->val;
        }
        else
        {
            return false;
        }
        bool bRight = isValidBST(root->right);
        return (bLeft && bRight);
    }
    
};
// @lc code=end

