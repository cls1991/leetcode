# coding: utf8


"""
    题目链接: https://leetcode.com/problems/evaluate-reverse-polish-notation/description.
    题目描述:

    Evaluate the value of an arithmetic expression in Reverse Polish Notation.

    Valid operators are +, -, *, /. Each operand may be an integer or another expression.

    Some examples:
      ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
      ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

"""


class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        operators = {
            '+': lambda x, y: y + x,
            '-': lambda x, y: y - x,
            '*': lambda x, y: y * x,
            '/': lambda x, y: int(float(y) / float(x))
        }
        for op in tokens:
            if op in operators:
                stack.append(operators[op](stack.pop(), stack.pop()))
            else:
                stack.append(int(op))

        return stack[0]
