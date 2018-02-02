/*
问题描述：
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
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
    
    /*
    //思路一：递归
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) 
            return true;
        return compare(root->left, root->right);
    }
    
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL) 
            return right == NULL;  
        if (right == NULL)
            return false;
        if (left->val != right->val) 
            return false;
        
        //分别拿左子树的右孩子和右子树的左孩子比较，左子树的左孩子和右子树的右孩子比较
        bool result1 = compare(left->right, right->left);
        bool result2 = compare(left->left, right->right);
        return result1 && result2;
    }
    */
    
    
    //思路二：非递归的方法，需要借用两个队列迭代实现(两个队列，左右子树进去的时候顺序相反)
    bool isSymmetric(TreeNode* root) {
        if (!root) 
            return true;
        
        queue<TreeNode*> qL, qR;
        qL.push(root->left);
        qR.push(root->right);
        while(!qL.empty() && !qR.empty()) {
            TreeNode* nodeL = qL.front(); qL.pop();
            TreeNode* nodeR = qR.front(); qR.pop();
            //有一个不存在那么就肯定不对称了
            if (nodeL && !nodeR || !nodeL && nodeR) 
                return false;
            //不用判断都存在，因为有一个存在就会过滤了，都不存在的话，循环就结束了
            if (nodeL) {
                //现在判断值
                if (nodeL->val != nodeR->val) 
                    return false;
                
                //然后左子树按照从左到右加入，右子树则从右到左
                qL.push(nodeL->left);
                qL.push(nodeL->right);
                qR.push(nodeR->right);
                qR.push(nodeR->left);
            }
        }
        
        return true;
    }
    
  
};

   
   
   
