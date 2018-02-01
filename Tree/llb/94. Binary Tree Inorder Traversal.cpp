/*
问题描述：
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2]
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
    思路一:中序遍历,可以考虑使用递归的方式
    */
//     vector<int> inorderTraversal(TreeNode* root) {
       
//         vector<int> resVec;
//         inorder(root, resVec);
//         return resVec;
//     }
    
//     void inorder(TreeNode* root, vector<int> &vec) {
//         if (root == NULL) {
//             return;
//         }
        
//         inorder(root->left, vec);
//         vec.push_back(root->val);
//         inorder(root->right, vec);
//     }
    
    /*
    思路二：利用栈的机制
        由于中序遍历是左->根->右，所以利用栈可以。
        思路是从根节点开始，先将根节点压入栈，然后再将其所有左子结点压入栈，然后取出栈顶节点，保存节点值，
        再将当前指针移到其右子节点上，若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中。
        这样就保证了访问顺序为左-根-右。
    */
    
//     vector<int> inorderTraversal(TreeNode* root) {
       
//         vector<int> resVec;
//         stack<TreeNode*> s;
//         TreeNode* p = root;
//         while (p || !s.empty()) {        //如果p不为null或者栈不为空就没有遍历完全
//             if (p) {
//                 s.push(p);
//                 p = p->left;
//             }
//             else {
//                 TreeNode *pTemp = s.top();
//                 s.pop();
//                 resVec.push_back(pTemp->val);
//                 p = pTemp->right;
//             }
//         }
        
//         return resVec;
//     }
    
    //写法三：就是先全部把左子树入栈，再一步一步往出弹
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resVec;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (p || !s.empty()) {        //如果p不为null或者栈不为空就没有遍历完全
            while (p) {
                s.push(p);
                p = p->left;
            }
            
            p = s.top();
            s.pop();
            resVec.push_back(p->val);
            p = p->right;
        }
        
        return resVec;
    }
    
    
    
};
