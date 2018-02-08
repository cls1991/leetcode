# coding: utf8


"""
    题目链接: https://leetcode.com/problems/house-robber-ii/description.
    题目描述:

    Note: This is an extension of House Robber.

    After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will
    not get too much attention. This time, all houses at this place are arranged in a circle. That means the first
    house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those
    in the previous street.

    Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount
    of money you can rob tonight without alerting the police.

    Credits:
    Special thanks to @Freezen for adding this problem and creating all test cases.

"""


class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        # 选/不选第一家, 取较大值
        return max(self.dynamic_rob(nums, 0), self.dynamic_rob(nums, 1))

    def dynamic_rob(self, nums, choice):
        if len(nums) <= choice:
            return 0
        elif len(nums) <= 1 + choice:
            return nums[choice]

        dp1 = nums[choice]
        dp2 = max(nums[choice], nums[1 + choice])
        for i in range(2 + choice, len(nums) - 1 + choice):
            dp1, dp2 = dp2, max(dp2, dp1 + nums[i])

        return dp2
