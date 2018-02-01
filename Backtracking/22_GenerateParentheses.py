# coding: utf8


"""
    题目链接: https://leetcode.com/problems/generate-parentheses/description.
    题目描述:

    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    For example, given n = 3, a solution set is:

    [
      "((()))",
      "(()())",
      "(())()",
      "()(())",
      "()()()"
    ]

"""


class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n < 0:
            return []
        elif n == 0:
            return ['']

        ans = []
        self.backtrack(n, 1, 0, '(', ans)

        return ans

    def backtrack(self, n, lc, rc, cur, ans):
        # 保证每个状态下, 左括号出现次数不低于右括号
        if lc < rc or max(lc, rc) > n:
            return
        elif lc == n and rc == n:
            ans.append(cur)
        else:
            self.backtrack(n, lc + 1, rc, cur + '(', ans)
            self.backtrack(n, lc, rc + 1, cur + ')', ans)
