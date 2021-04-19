/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
#include<vecotr>
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
    vector<int> vecResult;
    int getMinimumDifference(TreeNode* root) {
        vecResult.clear();
        travalTree(root);
        if (vecResult.size()<2)
        {
            return 0;
        }
        int nMinValue = INT_MAX;
        for (int i = 0; i < vecResult.size()-1; i++)
        {
            nMinValue = min(nMinValue, vecResult[i+1]-vecResult[i]);
        }
        return nMinValue;
    }
    void travalTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        travalTree(root->left);
        vecResult.push_back(root->val);
        travalTree(root->right);
    }
    
};
// @lc code=end

