# coding: utf8


"""
    题目链接: https://leetcode.com/problems/remove-element/description.
    题目描述:
    Given an array and a value, remove all instances of that value in-place and return the new length.

    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1)
    extra memory.

    The order of elements can be changed. It doesn't matter what you leave beyond the new length.

    Example:

        Given nums = [3,2,2,3], val = 3,

        Your function should return length = 2, with the first two elements of nums being 2.

"""


class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if not nums:
            return 0

        total = len(nums)
        counter = 0
        cursor = 0
        for i in range(0, total):
            if val == nums[i]:
                counter += 1
            else:
                nums[cursor] = nums[i]
                cursor += 1

        return total - counter
