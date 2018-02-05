# coding: utf8


"""
    题目链接: https://leetcode.com/problems/valid-perfect-square/description.
    题目描述:

    Given a positive integer num, write a function which returns True if num is a perfect square else False.

    Note: Do not use any built-in library function such as sqrt.

    Example 1:

        Input: 16
        Returns: True
    Example 2:

        Input: 14
        Returns: False
    Credits:
    Special thanks to @elmirap for adding this problem and creating all test cases.

"""


class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 1:
            return True

        left = 0
        right = num // 2
        while left <= right:
            mid = left + (right - left) // 2
            p = mid * mid
            if p == num:
                return True
            elif p < num:
                left = mid + 1
            else:
                right = mid - 1

        return False
