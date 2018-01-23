# coding: utf8


"""
    题目链接: https://leetcode.com/problems/rotate-array/description.
    题目描述:

    Rotate an array of n elements to the right by k steps.

    For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

    Note:
    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

    [show hint]

    Hint:
    Could you do it in-place with O(1) extra space?

    Related problem: Reverse Words in a String II

    Credits:
    Special thanks to @Freezen for adding this problem and creating all test cases.

"""


class Solution(object):
    def rotate_v1(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums or k <= 0:
            return

        ll = len(nums)
        nums_slice = nums[:]
        for i in range(ll):
            nums[(i + k) % ll] = nums_slice[i]

    def rotate_v2(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums or k <= 0:
            return

        ll = len(nums)
        start = 0
        k %= ll
        while k > 0:
            for i in range(k):
                nums[start + i], nums[start + ll - k + i] = nums[start + ll - k + i], nums[start + i]
            start += k
            ll -= k
            k %= ll

    def rotate_v3(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums or k <= 0:
            return

        def reverse_array(array, start, end):
            while end > start:
                array[end], array[start] = array[start], array[end]
                start += 1
                end -= 1

        ll = len(nums)
        k %= ll
        reverse_array(nums, 0, ll - 1)
        reverse_array(nums, 0, k - 1)
        reverse_array(nums, k, ll - 1)
