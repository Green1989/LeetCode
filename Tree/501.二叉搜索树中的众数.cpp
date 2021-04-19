/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
#include<vector>
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
    vector<int> vecRes;
    int nCount = 0;
    int nMaxCount = 0;
    int nPre = INT_MAX;
    vector<int> findMode(TreeNode* root) {
        searchBST(root);
        return vecRes;
    }
    void searchBST(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        searchBST(root->left);
        if (root->val == nPre)
        {
            nCount++;
        }
        else
        {
            nPre = root->val;
            nCount = 1;
        }
        if (nCount > nMaxCount)
        {
            vecRes.clear();
            vecRes.push_back(root->val);
            nMaxCount = nCount;
        }
        else if (nCount == nMaxCount)
        {
            vecRes.push_back(root->val);
        }
        searchBST(root->right);
    }
};
// @lc code=end

