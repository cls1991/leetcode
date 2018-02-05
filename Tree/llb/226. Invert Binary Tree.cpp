/*
问题描述：
Invert a binary tree.
     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
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
    
    //思路一：利用广度优先搜索(层序遍历)，判断然后交换每层，逐步进行
    /*
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) 
            return NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            //左右孩子存在的话，加入到队列中(也可以先转换，顺序不影响)
            if (node->left)   
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            
            //转换
            TreeNode* pTemp = node->left;
            node->left = node->right;
            node->right = pTemp;
        }
        
        return root;
    }
    */
    
    //思路二：递归构造
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) 
            return NULL;
        
        //注意：交换和循环递归左右子树顺序无所谓，仔细想想就是
        TreeNode* pTemp = root->left;
        root->left = root->right;
        root->right = pTemp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
