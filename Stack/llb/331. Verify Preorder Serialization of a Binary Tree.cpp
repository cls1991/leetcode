/*
问题描述：
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false

*/

/*
思路：
我们先发现规律：
1.数字的个数总比#少一个
2.最后一个一定是#
所以我们加入字符的时候不考虑最后一个#，所以此时数字和#那么总是相等的。
初始化一个为0的计数器，遇到数字加1，遇到#减一，合理的二叉树到最后计数器应该为0；
不能有连续三个及以上的#，如果计数器已经为0了，遇到#那就不对了（因为在正确的序列里，一个范围内的#是不可能大于数字的）
*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        //先解析字符串
        istringstream in(preorder);
        vector<string> v;
        string t = "";
        int count = 0;
        while (getline(in, t, ','))
            v.push_back(t);
        for (int i = 0; i < v.size()-1; i++) {
            if (v[i] == "#") {
                if (count == 0) 
                    return false;
                count--;
            }
            else {
                count++;
            }
        }
        
        if (count == 0 && v.back() == "#") {
            return true;
        } 
        else {
            return false;
        }
    }
};
