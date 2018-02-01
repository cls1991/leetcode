/*
问题描述：
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
思路：
假设一个二叉查找树如下：
         6
       /   \
      5     8
     /     / \
    1     7   9
     \      
      3  
     / \
    2   4
    
我们维护一个栈，暂且称之为最小元素栈。
我们在栈中存储的是一部分极小值，且栈顶一定是当前树中未访问过的结点中的最小结点。
在调用next()弹出最小结点时，需要把被弹出结点的右子树添加到栈中，
也就是把比当前最小结点大但是比次小结点小的那些结点中的一部分（不是全部，只是左孩子分支上的一部分）添加到栈中。
*/

class BSTIterator {
private:
    stack<TreeNode*> minStack;
    
public:
    BSTIterator(TreeNode *root) {
        //初始化时，把根节点的极左子节点全部入栈。那么栈顶元素就是最小的
        while (root != NULL) {
            minStack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !minStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        //找到栈顶，即为结果
        TreeNode* pTemp = minStack.top();
        minStack.pop();
        int result = pTemp->val;      
        //下来检查右子树，不为空则入栈，道理同样，一直向左子树寻找.最左就是最小的
        pTemp = pTemp->right;
        while(pTemp != NULL) {
            minStack.push(pTemp);
            pTemp = pTemp->left;
        }
        
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
