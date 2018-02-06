# coding: utf8


"""
    题目链接: https://leetcode.com/problems/first-bad-version/description.
    题目描述:

    You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version
    of your product fails the quality check. Since each version is developed based on the previous version, all the
    versions after a bad version are also bad.

    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the
    following ones to be bad.

    You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to
    find the first bad version. You should minimize the number of calls to the API.

    Credits:
    Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

"""


# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 1:
            return n

        left, right = 1, n
        while left <= right:
            mid = left + (right - left) // 2
            if isBadVersion(mid):
                right = mid - 1
            else:
                left = mid + 1

        return right + 1
