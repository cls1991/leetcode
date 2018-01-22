# coding: utf8


"""
    题目链接: https://leetcode.com/problems/pascals-triangle-ii/description.
    题目描述:

    Given an index k, return the kth row of the Pascal's triangle.

    For example, given k = 3,
    Return [1,3,3,1].

    Note:
    Could you optimize your algorithm to use only O(k) extra space?

"""


class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        elif rowIndex == 1:
            return [1, 1]

        triangle = [1, 1]
        for row in range(2, rowIndex + 1):
            a = triangle[0]
            for column in range(1, row):
                b = triangle[column]
                triangle[column] = a + b
                a = b
            triangle.append(1)

        return triangle
