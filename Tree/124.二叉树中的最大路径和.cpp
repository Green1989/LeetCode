/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include <conio.h>
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
    int nResutl = INT_MIN;
    int maxPathSum(TreeNode* root) {
        int nVal = INT_MIN;
        getMaxSum(root, nVal);
        return nVal;
    }
    int getMaxSum(TreeNode* root, int& val)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int nLeftSum = max(0, getMaxSum(root->left, val));
        int nRightSum = max(0 ,getMaxSum(root->right, val));
        int nCross = root->val + nLeftSum + nRightSum;
        int nRet = root->val + max(nLeftSum, nRightSum);
        val = max(val, max(nCross, nRet));
        return nRet;
    }
};
// @lc code=end

