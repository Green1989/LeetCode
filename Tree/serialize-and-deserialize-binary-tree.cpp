/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
#include<conio.h>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
        {
            return "";
        }
        string data = "";
        queue<TreeNode*> que;
        que.emplace(root);
        while (!que.empty())
        {
            int nSize = que.size();
            for (int i = 0; i < nSize; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if(cur == NULL)
                {
                    data.push_back('n');
                    data.push_back(',');
                }
                else
                {
                    data += to_string(cur->val);
                    data.push_back(',');
                    que.emplace(cur->left);
                    que.emplace(cur->right);
                }
            }            
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
        {
            return NULL;
        }        
        vector<string> vecData;
        split(data, vecData);
        TreeNode *root = new TreeNode(atoi(vecData[0].c_str()));
        queue<TreeNode*> que;
        que.emplace(root);
        int nIndex = 1;
        while (!que.empty() && nIndex < vecData.size())
        {
            int nSize = que.size();
            for (int i = 0; i < nSize; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if (vecData[nIndex] != "n" && vecData[nIndex] != "")
                {
                    cur->left = new TreeNode(atoi(vecData[nIndex].c_str()));
                    que.emplace(cur->left);
                }
                nIndex++;
                if (vecData[nIndex] != "n" && vecData[nIndex] != "")
                {
                    cur->right = new TreeNode(atoi(vecData[nIndex].c_str()));
                    que.emplace(cur->right);
                }
                nIndex++;
            }            
        }
        return root;
    }
    void split(const string& s, vector<string>& tokens, const string& delimiters = ",") 
    {     
        string::size_type lastPos = s.find_first_not_of(delimiters, 0);
        string::size_type pos = s.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos) 
        {
            tokens.push_back(s.substr(lastPos, pos - lastPos));//use emplace_back after C++11         
            lastPos = s.find_first_not_of(delimiters, pos);         
            pos = s.find_first_of(delimiters, lastPos);
        } 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
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
    Codec sol;
	int nTemp[] = {1,2,3,INT_MAX,INT_MAX,4,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    //int nTemp[] = {1,4,2,INT_MAX,INT_MAX,INT_MAX,3};
	//int nTemp[] = {2,NULL,3,NULL,4,NULL,5,c,6};

	TreeNode* root = creCBiTree(nTemp, sizeof(nTemp)/sizeof(int));
    string s = sol.serialize(root);
    cout << s << endl;
    TreeNode* head = sol.deserialize(s);    
    _getch();
    return 0;
}