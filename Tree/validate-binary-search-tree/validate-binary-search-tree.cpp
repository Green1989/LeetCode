/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include <queue>
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
    long m_nMaxValue = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }        
        bool bLeft = isValidBST(root->left);
        if (m_nMaxValue < root->val)
        {
            m_nMaxValue = root->val;
        }
        else
        {
            return false;
        }
        bool bRight = isValidBST(root->right);
        return (bLeft && bRight);
    }
    
};
// TreeNode* creCBiTree(int *p,int num)
// {	
// 	if (p==NULL||num<=0)
// 	{
// 		return NULL;
// 	}
//     TreeNode *leftNode = NULL;
//     // if (p[1] != INT_MAX)
//     // {
//     //     leftNode = new TreeNode(p[1]);
//     // }    
//     TreeNode *rightNode = NULL;
//     // if (p[2] != INT_MAX)
//     // {
//     //     rightNode = new TreeNode(p[2]);
//     // }
// 	TreeNode *root=new TreeNode(p[0]);
//     queue<TreeNode*> que;
//     que.push(root);
//     int nIndex = 1;
//     while (!que.empty() && nIndex < num)
//     {
//         int nSize = que.size();
//         for (int i = 0; i < nSize; i++)
//         {
//             TreeNode* curTreeNode = que.front();
//             que.pop();
//             if (p[nIndex] != INT_MAX)
//             {
//                 leftNode = new TreeNode(p[nIndex]);
//                 curTreeNode->left = leftNode;
//                 que.push(leftNode);
//             }
//             nIndex++;
//             if (p[nIndex] != INT_MAX)
//             {
//                 rightNode = new TreeNode(p[nIndex]);
//                 curTreeNode->right = rightNode;
//                 que.push(rightNode);
//             }
//             nIndex++;
//         }       
//     }
    
// 	return root;
// }
// int main()
// {
//     Solution sol;
// 	int nTemp[] = {0, INT_MAX, INT_MAX};
//     //int nTemp[] = {1,4,2,INT_MAX,INT_MAX,INT_MAX,3};
// 	//int nTemp[] = {2,NULL,3,NULL,4,NULL,5,NULL,6};

// 	TreeNode* root = creCBiTree(nTemp, sizeof(nTemp)/sizeof(int));
//     bool bRet = sol.isValidBST(root);
//     cout << bRet << endl;
//     _getch();
//     return 0;
// }

// @lc code=end

