/*\
问题描述：
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],

   1
    \
     2
    /
   3
 

return [3,2,1].
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
    
    //思路一：递归
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> vec;
//         postorder(root, vec);
//         return vec;
//     }
    
//     void postorder(TreeNode* root, vector<int> &vec) {
//         if (root == NULL) {
//             return;
//         }
        
//         postorder(root->left, vec);
//         postorder(root->right, vec);
//         vec.push_back(root->val);
//     }
    
    
    //思路二：利用栈的思想
    //先序遍历是：根->左->右，而后序遍历是：左->右->根.
    //所以可以修改一下先序遍历为：根->右->左，然后给值倒叙出来即可
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector<int> resVec;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty()) {
            TreeNode* pTemp = s1.top();
            s1.pop();
            s2.push(pTemp);      //将节点依次放入s2栈中，之后再倒序即可
            if (pTemp->left) 
                s1.push(pTemp->left);
            if (pTemp->right) 
                s1.push(pTemp->right);
        }
        
        while (!s2.empty()) {
            resVec.push_back(s2.top()->val);
            s2.pop();
        }
        
        return resVec;
    }
    
    
};
