/*
问题描述：
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

其实就是计算逆波兰数
*/

/*
思路：由于是数字运算，且都是二位运算。可以考虑简单的使用栈进行。
注意：注意弹出来的两个的值的运算顺序
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) 
            return 0;
        else if (tokens.size() == 1) 
            return stoi(tokens[0]);
        
        stack<int> numStack;
        for (int i=0; i < tokens.size(); ++i) {
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = numStack.top();
                numStack.pop();
                int num2 = numStack.top();
                numStack.pop();
                if (token == "+") 
                    numStack.push(num2 + num1);
                else if (token == "-") 
                    numStack.push(num2 - num1);
                else if (token == "*")
                    numStack.push(num2 * num1);
                else if (token == "/")
                    numStack.push(num2 / num1);
            }
            else {
                numStack.push(stoi(token));
            }
        }
        
        return numStack.top();
    }
};
