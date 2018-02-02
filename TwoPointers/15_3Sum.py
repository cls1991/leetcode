# coding: utf8


"""
    题目链接: https://leetcode.com/problems/3sum/description.
    题目描述:

    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets
    in the array which gives the sum of zero.

    Note: The solution set must not contain duplicate triplets.

    For example, given array S = [-1, 0, 1, 2, -1, -4],

        A solution set is:
        [
          [-1, 0, 1],
          [-1, -1, 2]
        ]

"""


class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums or len(nums) < 3:
            return []

        nums.sort()
        return self.three(nums, 0)

    def three(self, nums, target):
        ans = []
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, len(nums) - 1
            ct = target - nums[i]
            while left < right:
                cs = nums[left] + nums[right]
                if cs == ct:
                    ans.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                elif cs < ct:
                    left += 1
                else:
                    right -= 1

        return ans
