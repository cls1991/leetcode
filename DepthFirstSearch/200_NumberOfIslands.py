# coding: utf8


"""
    题目链接: https://leetcode.com/problems/number-of-islands/description.
    题目描述:

    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water
    and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid
    are all surrounded by water.

    Example 1:

        11110
        11010
        11000
        00000
        Answer: 1

    Example 2:

        11000
        11000
        00100
        00011
        Answer: 3

    Credits:
    Special thanks to @mithmatt for adding this problem and creating all test cases.

"""


class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid or not grid[0]:
            return 0

        islands = 0
        rows, columns = len(grid), len(grid[0])
        for i in range(rows):
            for j in range(columns):
                if self.dfs(grid, rows, columns, i, j):
                    islands += 1

        return islands

    def dfs(self, grid, rows, columns, i, j):
        if i < 0 or i >= rows or j < 0 or j >= columns or grid[i][j] == '0':
            return 0

        grid[i][j] = '0'
        self.dfs(grid, rows, columns, i - 1, j)
        self.dfs(grid, rows, columns, i, j + 1)
        self.dfs(grid, rows, columns, i + 1, j)
        self.dfs(grid, rows, columns, i, j - 1)

        return 1
