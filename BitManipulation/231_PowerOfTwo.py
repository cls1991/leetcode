# coding: utf8


"""
    题目链接: https://leetcode.com/problems/power-of-two/description.
    题目描述:

    Given an integer, write a function to determine if it is a power of two.

    Credits:
    Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

"""


class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 0:
            return False

        return n & (n - 1) == 0
