# coding: utf8


"""
    题目链接: https://leetcode.com/problems/single-number/description.
    题目描述:

    Given an array of integers, every element appears twice except for one. Find that single one.

    Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

"""


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        # 异或
        ans = nums[0]
        for i in range(1, len(nums)):
            ans ^= nums[i]

        return ans
