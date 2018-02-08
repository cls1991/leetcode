/*
问题描述：
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

就是验证是否为二叉查找树
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
    
    //思路一：利用BST的特性，然后将节点中序遍历，存储起来，那么就只需判断相邻两个数的数值是否是正确顺序即可
    //(中序遍历时非递归，利用栈也可以实现)
    /*
    bool isValidBST(TreeNode* root) {
        if (!root) 
            return true;
        
        vector<int> resVec;
        inorder(root, resVec);
        for (int i=0; i<resVec.size()-1; ++i) {
            if (resVec[i] >= resVec[i+1]) {
                return false;
            }
        }
        
        return true;
    }
    
    void inorder(TreeNode* node, vector<int> &vec){
        if (!node)
            return;
        
        inorder(node->left, vec);
        vec.push_back(node->val);
        inorder(node->right, vec);
    }
    */
    
    //思路二：利用递归实现
    bool isValidBST(TreeNode* root) {
        //注意：导入时要利用极大极小值(如果知道BST的最大最小也可以)
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBSTHelper(TreeNode* node, long min, long max) {
        if (!node)
            return true;
        
        if (node->val <= min || node->val >= max) {
            return false;
        }
        
        //分别再递归判断左右子树
        return isValidBSTHelper(node->left, min, node->val) && isValidBSTHelper(node->right, node->val, max);
    }
    
};

