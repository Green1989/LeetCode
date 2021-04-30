/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */
#include <conio.h>
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node. */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (root != NULL && root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        
        int nMinCameraCoverCount = 0;
        if(tarvelBT(root, nMinCameraCoverCount) == 0)
            nMinCameraCoverCount++;
        return nMinCameraCoverCount;
    }
    int tarvelBT(TreeNode* root, int& nMinCameraCoverCount)
    {
        if (root == NULL)
        {
            return 1;
        }
        int nLeft = tarvelBT(root->left, nMinCameraCoverCount);
        int nRight = tarvelBT(root->right, nMinCameraCoverCount);
        if (nLeft == 0 || nRight == 0)
        {
            nMinCameraCoverCount++;
            return 2;
        }
        else
        {
            return max(nLeft-1, nRight-1);
        }
    }
};
// @lc code=end

