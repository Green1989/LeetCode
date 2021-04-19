/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int nMidSum = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            nMidSum = root->left->val;
        }
        int nLeftSum = sumOfLeftLeaves(root->left);
        int nRightSum = sumOfLeftLeaves(root->right);
        return nLeftSum + nRightSum + nMidSum;     
    }
};
// @lc code=end

