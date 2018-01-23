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
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle:
            return 0

        la = len(haystack)
        lb = len(needle)

        if lb > la:
            return -1

        start = 0
        cp = 0
        ct = -1
        while start < la:
            if cp == lb:
                return ct
            if haystack[start] == needle[cp]:
                if cp == 0:
                    ct = start
                cp += 1
                start += 1
            else:
                if cp == 0:
                    start += 1
                elif start != cp:
                    print(start, cp)
                    start += lb
                    cp = 0
                    ct = 0
                else:
                    return ct

        return ct


if __name__ == '__main__':
    solution = Solution()
    print(solution.strStr('hello', 'll'))
    print(solution.strStr('aaaaa', 'baa'))
    print(solution.strStr('mississippi', 'issip'))
