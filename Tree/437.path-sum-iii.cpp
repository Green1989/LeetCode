/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */
#include <conio.h>
#include<queue>
#include<vector>
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
    vector<vector<int>> vecRes;
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> vecData;
        DFS(root, vecData);
        int nCount = 0;
        
        for (int i = 0; i < vecRes.size(); i++)
        {
            for (int j = 0; j < vecRes[i].size(); j++)
            {
                int nSum = 0;
                for (int k = j; k < vecRes[i].size(); k++)
                {
                    nSum += vecRes[i][k];
                    if (nSum == targetSum)
                    {
                        nCount++;
                    }
                }
            }
        }
        return nCount;
    }
    void DFS(TreeNode* root, vector<int> vecData)
    {
        vecData.push_back(root->val);
        if (root->left != nullptr)
        {            
            DFS(root->left, vecData);
        }
        if (root->right != nullptr)
        {
            DFS(root->right, vecData);
        }        
        if (root->left == nullptr && root->right == nullptr)
        {
            vecRes.emplace_back(vecData);
            return ;
        }
        vecData.pop_back();
    }
};
// @lc code=end


TreeNode* creCBiTree(int *p,int num)
{	
	if (p==NULL||num<=0)
	{
		return NULL;
	}
    TreeNode *leftNode = NULL;
    TreeNode *rightNode = NULL;
	TreeNode *root=new TreeNode(p[0]);
    queue<TreeNode*> que;
    que.push(root);
    int nIndex = 1;
    while (!que.empty() && nIndex < num)
    {
        int nSize = que.size();
        for (int i = 0; i < nSize; i++)
        {
            TreeNode* curTreeNode = que.front();
            que.pop();
            if (p[nIndex] != INT_MAX)
            {
                leftNode = new TreeNode(p[nIndex]);
                curTreeNode->left = leftNode;
                que.push(leftNode);
            }
            nIndex++;
            if (p[nIndex] != INT_MAX)
            {
                rightNode = new TreeNode(p[nIndex]);
                curTreeNode->right = rightNode;
                que.push(rightNode);
            }
            nIndex++;
        }       
    }
    
	return root;
}

int main()
{
    Solution sol;
    //int nTemp[] = {1,2,5,3,4,INT_MAX,6,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    //int nTemp[] = {1,2,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX};
    //int nTemp[] = {2,1,4,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX,INT_MAX};
    int nTemp[] = {10,5,-3,3,2,INT_MAX,11,3,-2,INT_MAX,1,INT_MAX,INT_MAX};
    TreeNode* root = creCBiTree(nTemp, sizeof(nTemp)/sizeof(int));
    int nRet = sol.pathSum(root, 8);
    cout << nRet << endl;
    _getch();
    return 0;
}
