# coding: utf8


"""
    题目链接: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description.
    题目描述:

    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.

    You may assume no duplicate exists in the array.

"""


class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # return self.binary_search_recursive(nums, 0, len(nums) - 1)
        return self.binary_search_iterative(nums, 0, len(nums) - 1)

    def binary_search_recursive(self, nums, l, r):
        if l > r:
            return nums[r]

        mid = l + (r - l) // 2
        if nums[mid] < nums[r]:
            return min(nums[mid], self.binary_search_recursive(nums, l, mid - 1))

        return min(nums[l], self.binary_search_recursive(nums, mid + 1, r))

    def binary_search_iterative(self, nums, l, r):
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] < nums[r]:
                r = mid
            else:
                l = mid + 1

        return nums[r]
