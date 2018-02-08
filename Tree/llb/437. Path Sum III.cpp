/*
问题描述：
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
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
    
    /*思考：
    利用前序遍历的思想，对于每个遍历到的节点进行处理，维护一个变量pre来记录之前路径的和，
    然后加上当前节点值，如果加上之后路径之和为sum，那么返回时要加一，然后递归调用左右子树
    */
    /*
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        return help(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int help (TreeNode* node, int pre, int &sum) {
        if (!node) 
            return 0;
        int cur = pre + node->val;
        return (cur == sum) + help(node->left, cur, sum) + help(node->right, cur, sum);
    }
    */
    
    //思考二：
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        vector<TreeNode*> vec;
        helper(root, sum, 0, vec, count);
        return count;
    }
    
    void helper(TreeNode* node, int sum, int curSum, vector<TreeNode*> &vec, int &count) {
        if (!node) 
            return;
        
        curSum += node->val;
        vec.push_back(node);
        //如果加入该节点后，值相等了，就多了条
        if (curSum == sum) 
            count++;
        int temp = curSum;
        //再判断加上该点后，它与之前的子路径之和
        for (int i=0; i<vec.size()-1; ++i) {
            temp -= vec[i]->val;
            if (temp == sum) 
                count++;
        }
        //然后判断左右子树
        helper(node->left, sum, curSum, vec, count);
        helper(node->right, sum, curSum, vec, count);
        vec.pop_back();
    }
};
