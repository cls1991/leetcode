# coding: utf8


"""
    题目链接:
    题目描述:

    Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

    For example,
        Given n = 3,

        You should return the following matrix:
        [
         [ 1, 2, 3 ],
         [ 8, 9, 4 ],
         [ 7, 6, 5 ]
        ]

"""


class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n <= 0:
            return []

        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        sx, sy = 0, 0
        digit = 1
        dr = 0
        changes = 1
        circle = 0
        rows = columns = n
        total = rows * columns
        matrix = [{} for _ in range(rows)]

        while total > 0:
            matrix[sx][sy] = digit
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
                circle += 1
                changes = 0

            total -= 1
            digit += 1

        for idx, sub_matrix in enumerate(matrix):
            matrix[idx] = [sub_matrix[key] for key in sorted(sub_matrix.keys())]

        return matrix
