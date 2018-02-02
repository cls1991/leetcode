# coding: utf8


"""
    题目链接: https://leetcode.com/problems/number-of-1-bits/description.
    题目描述:

    Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the
    Hamming weight).

    For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function
    should return 3.

    Credits:
    Special thanks to @ts for adding this problem and creating all test cases.

"""


class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        while n:
            n = n & (n - 1)
            ans += 1

        return ans
