/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

找到二叉平衡树的父节点
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
    
    //思路一：利用递归二分法，利用父节点大于左孩子，而小于右孩子的特性
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val) 
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val) 
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
    */
    
    //思路二：迭代循环，知道找到为止
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while (true) {
            if (node->val > p->val && node->val > q->val) 
                node = node->left;
            else if (node->val < p->val && node->val < q->val)
                node = node->right;
            else
                return node;
        }
    }
};
