/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {    
        if (root == nullptr)
        {
            return new TreeNode(val);
        }   
        bool bRet = travelralBST(root, val);
        if(!bRet)
        {
            TreeNode* cur = root;
            while (cur->right != nullptr)
            {
                cur = cur->right;
            }
            cur->right = new TreeNode(val);
        }
        return root;
    }
    bool travelralBST(TreeNode* root, int val)
    {
        bool bRet = false;
        if (root == nullptr)
        {
            return false;
        }
        bRet = travelralBST(root->left, val);
        if (bRet)
        {
            return bRet;
        }
        if (val < root->val)
        {
            TreeNode* cur = new TreeNode(val);
            cur->left = root->left;
            root->left = cur;
            return true;
        }
        bRet = travelralBST(root->right, val);      
        return bRet;
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
// 	int nTemp[] = {4,2,7,1,3};
//     //int nTemp[] = {1,4,2,INT_MAX,INT_MAX,INT_MAX,3};
// 	//int nTemp[] = {2,NULL,3,NULL,4,NULL,5,NULL,6};

// 	TreeNode* root = creCBiTree(nTemp, sizeof(nTemp)/sizeof(int));
//     TreeNode* cur = sol.insertIntoBST(root, 5);
//     cout << bRet << endl;
//     _getch();
//     return 0;
// }

// @lc code=end

