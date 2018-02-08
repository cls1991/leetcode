# coding: utf8


"""
    题目链接: https://leetcode.com/problems/house-robber/description.
    题目描述:

    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
    stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system
    connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount
    of money you can rob tonight without alerting the police.

    Credits:
    Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding
    additional test cases.

"""


class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums[0], nums[1])

        return self.dynamic_rob(nums)

    def dynamic_rob(self, nums):
        # 递推公式: dp[i] = max(dp[i-1], dp[i-2] + nums[i]), i > 2
        # dp[i]仅与dp[i-1], dp[i-2]相关, 只需存储这两个状态即可.
        dp1 = nums[0]
        dp2 = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            dp1, dp2 = dp2, max(dp2, dp1 + nums[i])

        return dp2
