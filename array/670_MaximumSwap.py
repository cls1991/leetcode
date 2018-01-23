# coding: utf8


"""
    题目链接: https://leetcode.com/problems/maximum-swap/description.
    题目描述:

    Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

    Example 1:
        Input: 2736
        Output: 7236
        Explanation: Swap the number 2 and the number 7.
        Example 2:
        Input: 9973
        Output: 9973
        Explanation: No swap.
    Note:
    The given number is in the range [0, 10^8].

"""


class Solution(object):
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num <= 0 or num > 100000000:
            return 0

        s = list(str(num))
        ll = len(s)
        pre = s[:]

        for i in range(ll - 2, -1, -1):
            pre[i] = max(pre[i], pre[i + 1])

        for i in range(ll):
            if s[i] < pre[i]:
                for j in range(ll - 1, i, -1):
                    if s[j] == pre[i]:
                        s[j], s[i] = s[i], s[j]
                        return int(''.join(s))

        return num
