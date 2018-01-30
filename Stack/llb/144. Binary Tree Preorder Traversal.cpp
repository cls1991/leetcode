/*
问题描述：
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].
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
    //前序遍历：根->左->右
    
    //思路一：递归
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> resVec;
//         preorder(root, resVec);
//         return resVec;
//     }
    
//     void preorder(TreeNode* root, vector<int> &vec) {
//         if (root == NULL) {
//             return;
//         }
        
//         vec.push_back(root->val);
//         preorder(root->left, vec);
//         preorder(root->right, vec);
//     }
    
    //思路二：利用栈。
    //1.把根节点压入到栈中。
    //2.循环检测栈是否为空，若不为空，则取出栈顶元素，保存值。
    //3.判断该值的右子树是否为空，若存在则push到栈中。再判断其左子树是否为空，若存在则push到栈中。
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        
        vector<int> resVec;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* pTemp = s.top();
            s.pop();
            resVec.push_back(pTemp->val);
            if (pTemp->right) 
                s.push(pTemp->right);
            if (pTemp->left) 
                s.push(pTemp->left);
        }
        
        return resVec;
    }
};
