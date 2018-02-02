# coding: utf8


"""
    题目链接: https://leetcode.com/problems/majority-element/description.
    题目描述:

    Given an array of size n, find the majority element. The majority element is the element that appears more than
    ⌊ n/2 ⌋ times.

    You may assume that the array is non-empty and the majority element always exist in the array.

    Credits:
    Special thanks to @ts for adding this problem and creating all test cases.

"""


class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = nums[0]
        cnt = 1

        for i in range(1, len(nums)):
            if cnt == 0:
                cnt += 1
                ans = nums[i]
            elif nums[i] == ans:
                cnt += 1
            else:
                cnt -= 1

        return ans
