/*
问题描述：

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.


Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
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
    思路一：利用递归
    思路二：利用树的几种遍历顺序来逐步进行判断，注：不能加入完全后再判断，因为相同的遍历顺序不一定能确定一个树
    */
    
    //实现一：
    /*
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == q;
        }
        
        //比较值
        bool isSameVal = p->val == q->val;
        //递归比较左右子树
        bool isSameLeft = isSameTree(p->left, q->left);
        bool isSameRight = isSameTree(p->right, q->right);
        
        return isSameVal && isSameLeft && isSameRight;
    }
    */
    
    
    //实现二：
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> sp, sq;
        if (p)
            sp.push(p);
        if (q)
            sq.push(q);
        while(!sp.empty() && !sq.empty()) {
            TreeNode* tp = sp.top();
            TreeNode* tq = sq.top();
            sp.pop();
            sq.pop();
            //判断栈顶元素值
            if (tp->val != tq->val)
                return false;
            
            //判断右子树，加入进去后判断栈的大小
            if (tp->right) 
                sp.push(tp->right);
            if (tq->right) 
                sq.push(tq->right);
            if (sp.size() != sq.size())
                return false;
            
            //判断左子树
            if (tp->left) 
                sp.push(tp->left);
            if (tq->left)
                sq.push(tq->left);
            if (sp.size() != sq.size()) 
                return false;
        }
        
        return sp.size() == sq.size();
    }
    
};
