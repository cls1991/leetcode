/*
问题描述：
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/*思考：
因为如果一个节点如果只有左子树或者右子树，我们不能取它左右子树中小的作为深度，因为那样会是0。
我们只有在叶子节点才能判断深度，当左右子树都为空时才是叶子节点。
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
    
    /*思考：因为如果一个节点如果只有左子树或者右子树，我们不能取它左右子树中小的作为深度，因为那样会是0。
      我们只有在叶子节点才能判断深度，当左右子树都为空时才是叶子节点。
    */
    
    //思路一：层序遍历，计算深度，直到出现某个节点的左右孩子都为NULL时，终止循环。
    /*
    int minDepth(TreeNode* root) {
        if (root == NULL) 
            return 0;
        
        queue<TreeNode*> q;
        int depth = 0;
        q.push(root);
        while (!q.empty()) {
            depth++;
            int n = q.size();
            for (int i=0; i<n ;++i) {
                TreeNode* pTemp = q.front();
                q.pop();
                if (pTemp->left) 
                    q.push(pTemp->left);
                if (pTemp->right)
                    q.push(pTemp->right);
                if (!pTemp->left && !pTemp->right) 
                    return depth;
            }
        }
    }
    */
    
    //思路二：利用递归的思想。
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL)
            return minDepth(root->right) + 1;
        if (root->right == NULL)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    
};
