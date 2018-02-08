/*
问题描述：

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
    
    /*由于是BST
    1.该结点无孩子：直接删除
    2.该节点只有一个孩子：则用该孩子代替被删节点
    3.左右孩子均有，需要调整后面所有的树节点
    注：需要考虑左右孩子有孩子的情况
    难点：删完节点后，还需要是一个二叉搜索树，所以补上的那个节点不一定是其左右孩子节点
    */
    
    
    /*方法一：递归：
    步骤：
    1.先可利用BST的左<根<右的特性找到要被删的节点。
    2.找到该节点，如果被删节点有一个孩子为空，那么就将另一个不为空的孩子代替即可。
    3.如果都不为空，那么可以找到左子树最右的节点或者右子树最左的节点代替被删节点均可以。然后用递归删除最左或者最右的节点即可。
    */
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) 
            return NULL;
        
        //找到被删节点
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } 
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            //如果找到该节点后，只有一个孩子
            if (!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            }
            //左右孩子都有
            else {
                //找到该节点右子树的最左孩子节点(左子树的最右孩子节点也可)
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                //用找到的最左孩子节点，替换被删除的节点(其实只是值的替换，并非真的删除节点)
                root->val = cur->val;
                //然后递归来删除右子树中最左的这个点(实际真的删除了)
                root->right = deleteNode(root->right, cur->val);   //为什么递归，因为有可能这个最左(右)的节点也可能右孩子
            }
        }
        
        return root;
    }
    
    
    //方法二：整个都可以使用，而非只是BST
    /*
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) 
            return NULL;
        
        //判断当找到该节点时
        if (root->val == key) {
            //这里考虑利用左子树的最右节点代替被删节点
            if (root->left) {
                TreeNode* cur = root->left;
                while(cur->right) {
                    cur = cur->right;
                }
                //找到最右点时，交换值即可（被更改的值，在后续递归中会删除）
                swap(root->val, cur->val);
            }
            else {
                //如果左子树不存在，直接返回右子树
                return root->right;
            }   
        }
        
        //然后循环左右子树
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        
        return root;
    }
    */
    
};
