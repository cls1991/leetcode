# coding: utf8


"""
    题目链接: https://leetcode.com/problems/climbing-stairs/description.
    题目描述:

    You are climbing a stair case. It takes n steps to reach to the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Note: Given n will be a positive integer.


    Example 1:

    Input: 2
    Output:  2
    Explanation:  There are two ways to climb to the top.

    1. 1 step + 1 step
    2. 2 steps
    Example 2:

    Input: 3
    Output:  3
    Explanation:  There are three ways to climb to the top.

    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step

"""


class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return n

        # return self.dynamic_climb_stairs(n)
        return self.dynamic_climb_stairs_optimization(n)

    def dynamic_climb_stairs(self, n):
        # 递推公式: dp[n] = dp[n-1]+dp[n-2], n > 2
        # 空间复杂度: O(n)
        dp = [0] * n
        dp[0] = 1
        dp[1] = 2
        for i in range(2, n):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n - 1]

    def dynamic_climb_stairs_optimization(self, n):
        # 优化: dp[n]仅与dp[n-1], dp[n-2]有关, 只需存储这两个状态即可
        # 空间复杂度: O(1)
        dp1 = 1
        dp2 = 2
        for i in range(2, n):
            dp1, dp2 = dp2, dp1 + dp2

        return dp2
