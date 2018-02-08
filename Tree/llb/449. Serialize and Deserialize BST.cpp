/*
问题描述：
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

//注意这个问题是要求你进行序列化和反序列化二叉查找树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    
    //思路一：采用层序遍历的方式进行，借助queue来实现，本质是BFS算法，并且得借助输入、输出流
    // Encodes a tree to a single string.
    /*
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        
        ostringstream os;         //cpp输出流
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                os << node->val << " ";      //如果存在改node，输出值和空格，负责输出#
                q.push(node->left);
                q.push(node->right);
            }
            else {
                os << "#";
            }
        }
        
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) 
            return NULL;
        
        istringstream is(data);
        queue<TreeNode*> q;
        string val = "";
        //生成根节点
        is >> val;
        TreeNode* root = new TreeNode(stoi(val));
        TreeNode* cur = root;
        q.push(cur);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            //一步步从序列里面读取node信息
            if (!(is >> val))
                break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                node->left = cur;
            }
            if (!(is >> val))
                break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                node->right = cur;
            }
        }
        
        return root;
    }
    */
    
    
    
    //思路二：利用递归的思想
    string serialize(TreeNode* root) {
        ostringstream os;
        serializeHelper(root, os);
        return os.str();
    }
    
    void serializeHelper(TreeNode* node, ostringstream &os) {
        if (!node) {
            os << "# ";       //注意写入的是#还有空格
        }
        else {
            os << node->val << " ";
            //然后加入左子树和右子树
            serializeHelper(node->left, os);
            serializeHelper(node->right, os);
        }
    }
    
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return deserializeHelper(is);
    }
    
    TreeNode* deserializeHelper(istringstream &is) {
        string val = "";
        is >> val;
        if (val == "#") 
            return NULL;
        //其他的需要生成新的node
        TreeNode *node = new TreeNode(stoi(val));
        node->left = deserializeHelper(is);
        node->right = deserializeHelper(is);
        return node;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
