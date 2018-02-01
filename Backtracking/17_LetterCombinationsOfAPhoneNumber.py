# coding: utf8


"""
    题目链接: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description.
    题目描述:

    Given a digit string, return all possible letter combinations that the number could represent.

    A mapping of digit to letters (just like on the telephone buttons) is given below.

    Input:Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    Note:
    Although the above answer is in lexicographical order, your answer could be in any order you want.

"""


class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []

        dtm = {'0': '', '1': '', '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv',
               '9': 'wxyz'}
        ans = []
        self.backtrack(digits, dtm, 0, '', ans)

        return ans

    def backtrack(self, digits, dtm, idx, s, ans):
        if len(s) == len(digits):
            ans.append(s)
        else:
            for i in range(idx, len(digits)):
                for c in dtm[digits[i]]:
                    self.backtrack(digits, dtm, i + 1, s + c, ans)
