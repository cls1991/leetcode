# coding: utf8


"""
    题目链接: https://leetcode.com/problems/valid-parentheses/description.
    题目描述:

    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is
    valid.

    The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

"""


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True

        if s[0] in [')', ']', '}']:
            return False

        stack = [s[0]]
        for i in range(1, len(s)):
            if s[i] == ')' and stack and stack[-1] == '(':
                stack.pop()
            elif s[i] == ']' and stack and stack[-1] == '[':
                stack.pop()
            elif s[i] == '}' and stack and stack[-1] == '{':
                stack.pop()
            else:
                stack.append(s[i])

        return True if not stack else False
