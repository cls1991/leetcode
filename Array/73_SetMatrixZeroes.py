# coding: utf8

"""
    题目链接: https://leetcode.com/problems/set-matrix-zeroes/description.
    题目描述:

    Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

    click to show follow up.

    Follow up:
    Did you use extra space?
    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?

"""


class Solution(object):
    def setZeroes_v1(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return

        rows = len(matrix)
        columns = len(matrix[0])
        zero_rows = [0 for _ in range(rows)]
        zero_columns = [0 for _ in range(columns)]

        for i in range(rows):
            for j in range(columns):
                if not matrix[i][j]:
                    zero_rows[i] = 1
                    zero_columns[j] = 1

        for i in range(rows):
            for j in range(columns):
                if zero_rows[i] or zero_columns[j]:
                    matrix[i][j] = 0

    def setZeroes_v2(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return

        rows = len(matrix)
        columns = len(matrix[0])
        zero_first_row = 0
        zero_first_column = 0

        for j in range(columns):
            if not matrix[0][j]:
                zero_first_row = 1
                break
        for i in range(rows):
            if not matrix[i][0]:
                zero_first_column = 1
                break

        for i in range(1, rows):
            for j in range(1, columns):
                if not matrix[i][j]:
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        for i in range(1, rows):
            for j in range(1, columns):
                if not matrix[0][j] or not matrix[i][0]:
                    matrix[i][j] = 0

        if zero_first_row:
            for j in range(columns):
                matrix[0][j] = 0
        if zero_first_column:
            for i in range(rows):
                matrix[i][0] = 0
