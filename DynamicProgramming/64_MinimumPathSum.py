# coding: utf8


"""
    题目链接: https://leetcode.com/problems/minimum-path-sum/description.
    题目描述:

    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the
    sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    Example 1:
    [[1,3,1],
     [1,5,1],
     [4,2,1]]
    Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.

"""


class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not any(grid):
            return 0

        return self.dynamic_min_path_sum(grid)

    # 动态规划:
    # 递推公式: dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j], i>=1, j>=1
    def dynamic_min_path_sum(self, grid):
        rows = len(grid)
        columns = len(grid[0])
        dp = [[0 for _ in range(columns)] for _ in range(rows)]
        dp[0][0] = grid[0][0]
        for i in range(1, rows):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for j in range(1, columns):
            dp[0][j] = dp[0][j - 1] + grid[0][j]

        for i in range(1, rows):
            for j in range(1, columns):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]

        return dp[rows - 1][columns - 1]
