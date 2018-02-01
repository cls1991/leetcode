/*
问题描述：
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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
    
    //思路：二叉搜索树始终满足：左<根<右，
    //所以，每次找到中间节点M，然后小于M的就是左子树，大于M的就是右子树。
    //然后模拟中序遍历生成树。
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return doSortArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* doSortArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) 
            return NULL;
        
        int mid = (left + right) / 2;
        //生成当前节点
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = doSortArrayToBST(nums, left, mid-1);
        node->right = doSortArrayToBST(nums, mid+1, right);
        return node;
    }
};
