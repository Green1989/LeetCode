/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return creatBST(nums, 0, nums.size()-1);  
    }
    TreeNode* creatBST(vector<int>& nums, int nLeft, int nRight)
    {
        if (nLeft > nRight)
        {
            return nullptr;
        }
        int nMid = nLeft + (nRight-nLeft)/2;       
        TreeNode* root = new TreeNode(nums[nMid]);
        root->left = creatBST(nums, nLeft, nMid-1);
        root->right = creatBST(nums, nMid+1, nRight);
        return root;
    }
    //TreeNode* creatBST(int nums)
};
// @lc code=end

