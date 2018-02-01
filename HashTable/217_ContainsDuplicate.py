# coding: utf8


"""
    题目链接: https://leetcode.com/problems/contains-duplicate/description.
    题目描述:

    Given an array of integers, find if the array contains any duplicates. Your function should return true if any
    value appears at least twice in the array, and it should return false if every element is distinct.

"""


class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums:
            return False

        # 查重
        return len(nums) != len(set(nums))
