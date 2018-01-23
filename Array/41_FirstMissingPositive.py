# coding: utf8


"""
    题目链接: https://leetcode.com/problems/first-missing-positive/description.
    题目描述:
    Given an unsorted integer array, find the first missing positive integer.

    For example,
        Given [1,2,0] return 3,
        and [3,4,-1,1] return 2.

    Your algorithm should run in O(n) time and uses constant space.

"""


class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ll = len(nums)

        for i in range(ll):
            while 0 < nums[i] <= ll and nums[i] != i + 1:
                idx = nums[i] - 1
                if nums[idx] == nums[i]:
                    break
                nums[i], nums[idx] = nums[idx], nums[i]
        for i in range(ll):
            if nums[i] != i + 1:
                return i + 1

        return ll + 1
