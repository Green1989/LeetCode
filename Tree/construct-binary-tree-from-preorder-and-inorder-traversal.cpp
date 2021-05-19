/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <conio.h>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return nullptr;
        }       
       return traveral(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* traveral(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight)//区间左闭右开
    {
        if (preLeft >= preRight)
        {
            return nullptr;
        }
        int nTarget = preorder[preLeft];
        TreeNode* root = new TreeNode(nTarget);
        if (preRight - preLeft == 1)
        {
            return root;
        }        
        int nInorderCutIndex = -1;
        for (int i = inLeft; i < inorder.size(); i++)
        {
            if (inorder[i] == nTarget)
            {
                nInorderCutIndex = i;
                break;
            }
        }
        if (nInorderCutIndex < 0)
        {
            return nullptr;
        }        
        int nCurLeftChildInLeft = inLeft;
        int nCurLeftChildInRight = nInorderCutIndex;
        int nCurRightChildInLeft = nInorderCutIndex+1;
        int nCurRightChildInRight = inRight;

        int nCurLeftChildPreLeft = preLeft+1;
        int nCurLeftChildPreRight = preLeft+1+(nCurLeftChildInRight-nCurLeftChildInLeft);
        int nCurRightChildPreLeft = nCurLeftChildPreRight;
        int nCurRightChildPreRight = preRight;

        root->left = traveral(preorder, nCurLeftChildPreLeft, nCurLeftChildPreRight, inorder, nCurLeftChildInLeft, nCurLeftChildInRight);       
        root->right = traveral(preorder, nCurRightChildPreLeft, nCurRightChildPreRight, inorder, nCurRightChildInLeft, nCurRightChildInRight);
        return root;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    vector<int> preorder = {1,2};
    vector<int> inorder = {2,1};
    TreeNode* root = sol.buildTree(preorder, inorder);
    _getch();
    return 0;
}
