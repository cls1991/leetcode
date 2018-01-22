# coding: utf8


"""
    题目链接: https://leetcode.com/problems/pascals-triangle/description.
    题目描述:

    Given numRows, generate the first numRows of Pascal's triangle.

    For example,
        given numRows = 5,

        Return

        [
             [1],
            [1,1],
           [1,2,1],
          [1,3,3,1],
         [1,4,6,4,1]
        ]

"""


class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        elif numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1, 1]]

        triangles = [[1], [1, 1]]
        for row in range(2, numRows):
            triangle = [1]
            for column in range(1, row):
                triangle.append(triangles[row - 1][column - 1] + triangles[row - 1][column])
            triangle.append(1)
            triangles.append(triangle)

        return triangles
