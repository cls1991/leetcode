/*
问题描述：
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> vec;
        help(root, sum, vec, res);
        return res;
    }
    
    void help(TreeNode* root, int sum, vector<int> vec, vector<vector<int>> &res) {
        if (!root) {
            return;
        }
    
        //叶子节点并且值相等就结束
        if (!root->left && !root->right && root->val == sum) {
            vec.push_back(root->val);
            res.push_back(vec);
            return;
        }
        
        //非叶子节点都要添加进来
        vec.push_back(root->val);
        if (root->left) {
            help(root->left, sum-root->val, vec, res);
        }
        if (root->right) {
            help(root->right, sum-root->val, vec, res);
        }
        
    }
};
