/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        bool bIsBalanced = true;
        getChildTreeNodeCounts(root, bIsBalanced);
        return bIsBalanced;

    }
    int getChildTreeNodeCounts(TreeNode* node, bool& bIsBalanced)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int nLeftChildTreeNodeCounts = getChildTreeNodeCounts(node->left, bIsBalanced);
        int nRightChildTreeNodeCounts = getChildTreeNodeCounts(node->right, bIsBalanced);
        if(abs(nLeftChildTreeNodeCounts - nRightChildTreeNodeCounts) > 1)
        {
            bIsBalanced = false;
        }
        return 1 + max(nLeftChildTreeNodeCounts, nRightChildTreeNodeCounts);        
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
// 	int nTemp[] = {1,INT_MAX,2,INT_MAX,3};
//     //int nTemp[] = {1,4,2,INT_MAX,INT_MAX,INT_MAX,3};
// 	//int nTemp[] = {2,NULL,3,NULL,4,NULL,5,NULL,6};

// 	TreeNode* root = creCBiTree(nTemp, sizeof(nTemp)/sizeof(int));
//     bool bRet = sol.isBalanced(root);
//     cout << bRet << endl;
//     _getch();
//     return 0;
// }

// @lc code=end

