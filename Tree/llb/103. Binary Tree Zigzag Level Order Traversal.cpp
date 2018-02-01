/*
问题描述：
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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

/*思路：
    从上往下按层遍历二叉树，将每层的节点放到该层对应的数组中
    最后将总数组中的奇数层（从0开始计数）的子数组翻转一下即可
*/

struct LevelNode {
    TreeNode *node;
    int level;
    LevelNode(TreeNode *n, int l):node(n), level(l){}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> resVec {};
        if (root == NULL) {
            return resVec;
        }
        
        queue<LevelNode> q;
        q.push(LevelNode(root, 0));
        while(!q.empty()) {
            LevelNode cur = q.front();
            q.pop();
            TreeNode *p = cur.node;
            if (p) {
                //还没有加入该层，或者说是一个新层
                if (resVec.size() <= cur.level) {
                    vector<int> tempVec;
                    tempVec.push_back(p->val);
                    resVec.push_back(tempVec);
                }
                else {
                    resVec[cur.level].push_back(p->val);
                }
                
                //然后再判断左右子树
                LevelNode left(p->left, cur.level+1);
                LevelNode right(p->right, cur.level+1);
                q.push(left);
                q.push(right);
            }
        }
        
        //翻转奇数层
        for (int i=1; i<resVec.size(); i+=2) {
            reverse(resVec[i].begin(), resVec[i].end());
        }
        
        return resVec;
    }
};
