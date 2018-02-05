/*
问题描述：
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
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
    
    //思考：还是要利用递归的思想，写个递归计算深度的方法，然后递归判断左右子树的方法
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL) 
            return true;
        
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        return abs(leftDepth-rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getDepth(TreeNode* root) {
        if (root == NULL) 
            return 0;
        
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};
