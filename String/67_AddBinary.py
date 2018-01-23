# coding: utf8


"""
    题目链接: https://leetcode.com/problems/add-binary/description.
    题目描述:

    Given two binary strings, return their sum (also a binary string).

    For example,
        a = "11"
        b = "1"
        Return "100".

"""


class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if not a:
            return b
        if not b:
            return a

        result = []
        la = len(a)
        lb = len(b)
        ll = min(la, lb)
        lr = max(la, lb)
        ra = a[::-1]
        rb = b[::-1]
        carry = 0

        for i in range(ll):
            vs = int(ra[i]) + int(rb[i]) + carry
            if vs >= 2:
                carry = 1
            else:
                carry = 0
            result.append(str(vs % 2))

        for i in range(ll, lr):
            if lr == la:
                vs = int(ra[i]) + carry
            else:
                vs = int(rb[i]) + carry
            if vs >= 2:
                carry = 1
            else:
                carry = 0
            result.append(str(vs % 2))

        if carry:
            result.append(str(carry))

        result.reverse()

        return ''.join(result)
