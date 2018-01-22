# coding: utf8


"""
    题目链接: https://leetcode.com/problems/spiral-matrix/description.
    题目描述:
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

    For example,
    Given the following matrix:

        [
         [ 1, 2, 3 ],
         [ 4, 5, 6 ],
         [ 7, 8, 9 ]
        ]
    You should return [1,2,3,6,9,8,7,4,5].

"""


class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []

        spiral_array = []
        rows = len(matrix)
        columns = len(matrix[0])
        total = rows * columns
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        sx, sy = 0, 0
        dr = 0
        changes = 1
        circle = 0

        while total > 0:
            spiral_array.append(matrix[sx][sy])
            if dr == 0 and sy == columns - circle - 1:
                dr = 1
                changes += 1
            elif dr == 1 and sx == rows - circle - 1:
                dr = 2
                changes += 1
            elif dr == 2 and sy == circle:
                dr = 3
                changes += 1
            elif dr == 3 and sx == circle:
                dr = 0
                changes += 1

            dx, dy = directions[dr]
            sx, sy = sx + dx, sy + dy
            if changes == 4:
                changes = 0
                circle += 1
            total -= 1

        return spiral_array
