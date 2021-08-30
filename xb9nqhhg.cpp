#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
#include<istream>
#include<string>
#include<sstream>
#include<iostream>
#include<conio.h>
#include<assert.h>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class CBTInserter {
private:
    TreeNode* m_root;
    queue<TreeNode*> m_que;
public:
    CBTInserter(TreeNode* root) {
        m_root = root;
        if (m_root != nullptr)
        {
            queue<TreeNode*> que;
            que.push(m_root);
            while (!que.empty())
            {
                int nSize = que.size();
                for(int i = 0; i < nSize; i++)
                {
                    TreeNode* cur = que.front();
                    if (cur->left == nullptr || cur->right == nullptr)
                    {
                        m_que.push(cur);
                    }
                    if (cur->left != nullptr)
                        que.push(cur->left);
                    if (cur->right != nullptr)
                        que.push(cur->right);
                    que.pop();
                }
            }
        }
    }
    
    int insert(int v) {
        if (m_root == nullptr)
        {
            m_root = new TreeNode(v);
            return v;
        }        
        queue<TreeNode*> que;
        que.push(m_root);
        while (!que.empty())
        {
            int nSize = que.size();
            for(int i = 0; i < nSize; i++)
            {
                TreeNode* cur = que.front();
                if (cur->left == nullptr)
                {
                    cur->left = new TreeNode(v);
                    return cur->val;
                }
                else if (cur->right == nullptr)
                {
                    cur->right = new TreeNode(v);
                    return cur->val;
                }
                que.push(cur->left);
                que.push(cur->right);
                que.pop();
            }
        }
        return v;        
    }    
    TreeNode* get_root() {
        return m_root;
    }
};
