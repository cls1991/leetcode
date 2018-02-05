/*
问题描述：

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    
    //思路一：递归
    /*
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || !root->left && !root->right) 
            return 0;
        
        int res = 0;   
        //分别左右两支开始进行
        help(root->left, true, res);
        help(root->right, false, res);
        
        return res;
    }
    
    void help(TreeNode* root, bool isLeft, int &res) {
        if (!root)
            return;
        if (!root->left && !root->right && isLeft)   //如果是叶子节点并且是左孩子
            res += root->val;
        help(root->left, true, res);
        help(root->right, false, res);
    }
    */
    
    //写法二：
    /*
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) 
            return 0;
        
        //如果该节点的左孩子存在，但它是叶子节点。那就加上自己再计算右子树
        if (root->left && !root->left->left && !root->left->right)
            return root->left->val + sumOfLeftLeaves(root->right);
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
    */
    
    //思路二：利用层序遍历，逐个相加计算
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || !root->left && !root->right) {
            return 0;
        }
        
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            //如果是左边叶子节点
            if (node->left && !node->left->left && !node->left->right)
                res += node->left->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        
        return res;
    }
    
    
};
