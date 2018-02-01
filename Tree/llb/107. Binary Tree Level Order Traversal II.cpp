/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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


/*
思路一：利用层序遍历，最后整提翻转一下
*/

/*
struct LevelNode {
    TreeNode* node;
    int level;
    LevelNode(TreeNode* n, int l):node(n), level(l) {};
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> tempVec {};
        if (root == NULL) 
            return tempVec;
        
        //利用队列进行层序遍历
        queue<LevelNode> q;
        q.push(LevelNode(root, 0));
        while (!q.empty()) {
            LevelNode cur = q.front();
            q.pop();
            TreeNode *pNode = cur.node;
            if (pNode) {
                //还没有加入该层
                if (tempVec.size() <= cur.level) {
                    vector<int> vec;
                    vec.push_back(pNode->val);
                    tempVec.push_back(vec);
                }
                else {
                    tempVec[cur.level].push_back(pNode->val);
                }
                
                //判断左右子树，加入下层
                LevelNode left(pNode->left, cur.level+1);
                LevelNode right(pNode->right, cur.level+1);
                q.push(left);
                q.push(right);
            }
        }
        
        //将大容器反序
        vector<vector<int>> resVec {};
        for (int i=tempVec.size()-1; i>=0; i--)
            resVec.push_back(tempVec[i]);
        
        return resVec;
    }
};

*/

/*
写法二：利用层遍历，用一个队列保存当前层的节点，然后加入到一个栈中，最后导出来即可
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> resVec {};
        if (root == NULL) 
            return resVec;
        
        stack<vector<int>> s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vec;        //保存当前该层的值
            int n = q.size();       //记录当前该层的节点数
            //依次从左到右弹出该层节点，保证for循环结束后，该层全部的节点出队，该层下层的全部节点按照从左到右入队
            for (int i=0; i<n; ++i) {
                TreeNode* pTemp = q.front();
                q.pop();
                vec.push_back(pTemp->val);
                if (pTemp->left)
                    q.push(pTemp->left);
                if (pTemp->right)
                    q.push(pTemp->right);
            }
            s.push(vec);
        }
        
        //再把栈中的值倒出来，生成正确的顺序
        while (!s.empty()) {
            resVec.push_back(s.top());
            s.pop();
        }
        
        return resVec;
    }
    
};
