/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */
#include<queue>
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int nRet = 0;
        while (!que.empty())
        {
            int nSize = que.size();
            for (int i = 0; i < nSize; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left != nullptr)
                {
                    que.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    que.push(cur->right);
                }
                if (i == 0)
                {
                    nRet = cur->val;
                }
            }
        }
        return nRet;
    }
};
// @lc code=end

