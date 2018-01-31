/*
问题描述：
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

解析字符串
*/

/*
思路：借助递归的思想，找到每段括号内的字符。然后其他判断各类型的字符
*/

class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return helper(pos, s);
    }
    
    string helper(int &pos, string s) {
        int num = 0;          //记录数字的值
        string word = "";
        for (; pos < s.size(); pos++) {
            char cur = s[pos];
            if (cur == '[') {
                string curStr = helper(++pos, s);        //数字重复，递归调用获取[]内的字符串
                while (num > 0) {
                    word += curStr;
                    num--;
                }
            } 
            else if (cur == ']') {
                return word;
            }
            else if (cur >= '0' && cur <= '9') {
                num = num*10 + cur - '0';       //cur转为数字
            }
            else {
                word += cur;      
            }
        }
        return word;
    }
};
