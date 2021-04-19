/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
#include <vector>
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
    void getMaxValue(vector<int>& nums, int& nMaxValue, int& nIndex)
    {
        nMaxValue = nums[0];
        nIndex = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nMaxValue < nums[i])
            {
                nMaxValue = nums[i];
                nIndex = i;
            }
        }
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
        {
            return nullptr;
        }
        int nMaxValue = nums[0];
        int nIndex = 0;
        getMaxValue(nums, nMaxValue, nIndex);
        TreeNode* root = new TreeNode(nMaxValue);
        vector<int> vecLeft(nums.begin(), nums.begin() + nIndex);
        vector<int> vecRight(nums.begin() + nIndex + 1, nums.end());
        root->left = constructMaximumBinaryTree(vecLeft);
        root->right = constructMaximumBinaryTree(vecRight);
        return root;
    }
    
};
// @lc code=end

