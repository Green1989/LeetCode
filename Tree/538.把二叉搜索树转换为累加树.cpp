/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int nLastValue = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        convertBST(root->right);
        root->val += nLastValue;
        nLastValue = root->val;
        convertBST(root->left);
        return root;
    }
    // void travelBST(TreeNode* root)
    // {
    //     if (root == nullptr)
    //     {
    //         nLastValue = 0;
    //         return ;
    //     }
    //     travelBST(root->right);
    //     root->val += nLastValue;
    //     nLastValue = root->val;
    //     // if (root->right != nullptr)
    //     // {
    //     //     TreeNode* cur = root->right;
    //     //     while (cur->left != nullptr)
    //     //     {
    //     //         cur = cur->left;
    //     //     }
    //     //     root->val += cur->val;
    //     //     nLastValue = root->val;
    //     // }
    //     travelBST(root->left);
    //     return ;
    // }
};
// @lc code=end

