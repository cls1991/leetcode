# coding: utf8


"""
    题目链接: https://leetcode.com/problems/sqrtx/description.
    题目描述:

    Implement int sqrt(int x).

    Compute and return the square root of x.

    x is guaranteed to be a non-negative integer.


    Example 1:

        Input: 4
        Output: 2
    Example 2:

        Input: 8
        Output: 2
    Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be
    truncated.

"""


class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x <= 1:
            return x

        left = 0
        right = x // 2
        while left <= right:
            mid = left + (right - left) // 2
            if mid * mid <= x:
                left = mid + 1
            else:
                right = mid - 1

        return right
