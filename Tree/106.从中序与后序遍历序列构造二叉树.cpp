/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }
        return traveral(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    TreeNode* traveral(vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int postLeft, int postRight)
    {
        if (inLeft == inRight)
        {
            return nullptr;
        }
        int nTarget = postorder[postRight-1];
        TreeNode* root = new TreeNode(nTarget);
        if (inRight-inLeft == 1)
        {
            return root;
        }
        int nCurRootIndex = -1;
        for (int i = inLeft; i < inRight; i++)
        {
            if (inorder[i] == nTarget)
            {
                nCurRootIndex = i;
                break;
            }
        }
        if (nCurRootIndex < 0)
        {
            return nullptr;
        }
        int nCurLeftChildInLeft = inLeft;
        int nCurLeftChildInRight = nCurRootIndex;
        int nCurRightChildInLeft = nCurRootIndex+1;
        int nCurRightChildInRight = inRight;

        int nCurLeftChildPostLeft = postLeft;
        int nCurLeftChildPostRight = postLeft + (nCurLeftChildInRight-nCurLeftChildInLeft);
        int nCurRightChildPostLeft = nCurLeftChildPostRight;
        int nCurRightChildPostRight = postRight-1;

        root->left = traveral(inorder, nCurLeftChildInLeft, nCurLeftChildInRight, postorder, nCurLeftChildPostLeft, nCurLeftChildPostRight);       
        root->right = traveral(inorder, nCurRightChildInLeft, nCurRightChildInRight, postorder, nCurRightChildPostLeft, nCurRightChildPostRight);
        return root;
    }
};
// @lc code=end

