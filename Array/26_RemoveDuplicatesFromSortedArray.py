# coding: utf8


"""
    题目链接: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description.
    题目描述:
    Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new
    length.

    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1)
    extra memory.

    Example:

        Given nums = [1,1,2],

        Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
        It doesn't matter what you leave beyond the new length.

"""


class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        cursor = 0
        for i in range(1, len(nums)):
            if nums[cursor] != nums[i]:
                cursor += 1
                nums[cursor] = nums[i]

        return cursor + 1
