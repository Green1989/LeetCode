/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* cur = root;
        if(root == nullptr || low > high)
        {
            return nullptr;
        }
        while (cur->val > high)//区间都在左子树
        {
            cur = cur->left;
            delete root;
            root = cur;
        }
        while (cur->val < low)//区间都在右子树
        {
            cur = cur->right;
            delete root;
            root = cur;
        }
        
    }
    TreeNode* deleteLowChildTree(TreeNode* root, int key, TreeNode* pre) {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (key > root->val)
        {
            if (pre != nullptr)//
            {
                if (key <= pre->val)
                {
                    TreeNode* cur = root->right;
                    while (cur != nullptr && cur->val <= key)
                    {
                        if (cur->right == nullptr || cur->right->val >= key)
                        {
                            break;
                        }
                        cur = cur->right;
                    }
                    while (cur != nullptr && cur->val >= key)
                    {
                        cur = cur->left;
                    }
                    deleteTree(cur);
                    cur = root->right;
                    deleteTree(root);
                    return cur;        
                }
            }            
            TreeNode* cru = root->right;
            //root->left = deleteLowChildTree(root->left, key);
        }
        else if (key > root->val)
        {
            //root->right = deleteLowChildTree(root->right, key);
        }
        else
        {
            
        }
        root->left = deleteLowChildTree(root->left, key, root);
        

        root->right = deleteLowChildTree(root->right, key, root);      
        return root;
    }
    void deleteTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        return;
    }
};
// @lc code=end

