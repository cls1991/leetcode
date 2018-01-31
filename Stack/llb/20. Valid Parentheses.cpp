/*
问题描述：
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

//思路：首先想到的就是利用栈的机制，左括号进栈，右括号出栈


// class Solution {
// public:
//     bool isValid(string s) {
//         //思路：首先想到的就是利用栈的机制，左括号进栈，右括号出栈
//         stack<char> pareStack;
//         for (char &c : s) {
//             switch (c) {
//                 case '(':
//                 case '[':
//                 case '{': 
//                     pareStack.push(c);
//                     break;
                    
//                 case ')':
//                     if (pareStack.empty() || pareStack.top() != '(') {
//                         return false;
//                     }
//                     else {
//                         pareStack.pop();
//                     }
//                     break;
                    
//                 case ']':
//                     if (pareStack.empty() || pareStack.top() != '[') {
//                         return false;
//                     }
//                     else {
//                         pareStack.pop();
//                     }
//                     break;
                    
//                 case '}':
//                     if (pareStack.empty() || pareStack.top() != '{') {
//                         return false;
//                     }
//                     else {
//                         pareStack.pop();
//                     }
//                     break;
                    
//                 default: ;
//             }
//         }
        
//         return pareStack.empty();
//     }
// };



//写法二：

class Solution {
public:
    bool isValid(string s) {
        //思路：首先想到的就是利用栈的机制，左括号进栈，右括号出栈
        stack<char> pareStack;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                pareStack.push(s[i]);
            }
            else {
                if (pareStack.empty()) 
                    return false;
                if (s[i] == ')' && pareStack.top() != '(') 
                    return false;
                if (s[i] == '}' && pareStack.top() != '{')
                    return false;
                if (s[i] == ']' && pareStack.top() != '[')
                    return false;
                
                pareStack.pop();
            }
        }
        
        return pareStack.empty();
    }
};
