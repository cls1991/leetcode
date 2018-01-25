# coding: utf8


"""
    题目链接: https://leetcode.com/problems/implement-strstr/description.
    题目描述:

    Implement strStr().

    Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Example 1:

        Input: haystack = "hello", needle = "ll"
        Output: 2
    Example 2:

        Input: haystack = "aaaaa", needle = "bba"
        Output: -1

"""


class Solution(object):
    def strStr_v1(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle:
            return 0

        la = len(haystack)
        lb = len(needle)

        for i in range(la - lb + 1):
            start = i
            for j in range(lb):
                if haystack[start] != needle[j]:
                    break
                start += 1

            if start - i == lb:
                return i

        return -1
