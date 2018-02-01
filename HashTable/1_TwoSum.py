# coding: utf8


"""
    题目链接: https://leetcode.com/problems/two-sum/description.
    题目描述:

    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:
        Given nums = [2, 7, 11, 15], target = 9,

        Because nums[0] + nums[1] = 2 + 7 = 9,
        return [0, 1].

"""


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return []

        ans = []
        hp = {}
        for i, n in enumerate(nums):
            if target - n in hp:
                ans.append(hp[target - n])
                ans.append(i)
                return ans

            hp[n] = i

        return ans
