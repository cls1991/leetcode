/*
问题描述
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    //计算树的深度
    //思路一：递归
    /*
    int maxDepth(TreeNode* root) {
        if (root == NULL) 
            return 0;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int depth = 1 + max(leftDepth, rightDepth);
        return depth;
    }
    */
    
    //思路二：利用层序遍历计算（每层把自己的层的node全循环一遍，记到queue中，然后在该层全部弹出来，并且把下层的节点全部保存进去）
    int maxDepth(TreeNode* root) {
        if (root == NULL) 
            return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            depth++;
            int n = q.size();    //计算当前层的节点数，然后每个弹出来，再加入下层的所有节点
            for (int i=0; i<n; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) 
                    q.push(temp->left);
                if (temp->right) 
                    q.push(temp->right);
            }
        }   
         
        return depth;
    }
    
    
    
    
};
