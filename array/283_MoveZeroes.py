# coding: utf8


"""
    题目链接: https://leetcode.com/problems/move-zeroes/description.
    题目描述:

    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the
    non-zero elements.

    For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

    Note:
    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
    Credits:
    Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

"""


class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return

        first_zero_pos = 0
        ll = len(nums)

        for i in range(1, ll):
            if nums[i] != 0 and nums[first_zero_pos] == 0:
                nums[first_zero_pos], nums[i] = nums[i], nums[first_zero_pos]
                first_zero_pos += 1
            elif nums[first_zero_pos] != 0:
                first_zero_pos = i
