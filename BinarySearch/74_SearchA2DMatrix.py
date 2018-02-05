# coding: utf8


"""
    题目链接: https://leetcode.com/problems/search-a-2d-matrix/description.
    题目描述:

    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    For example,

    Consider the following matrix:

    [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    Given target = 3, return true.

"""


class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not any(matrix) or target < matrix[0][0] or target > matrix[-1][-1]:
            return False

        return self.searchMatrixColumns(matrix, self.searchMatrixRows(matrix, target), target)

    def searchMatrixRows(self, matrix, target):
        left = 0
        right = len(matrix) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if matrix[mid][0] <= target:
                left = mid + 1
            else:
                right = mid - 1

        return right

    def searchMatrixColumns(self, matrix, row, target):
        left = 0
        right = len(matrix[row]) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return False
