# coding: utf8


"""
    题目链接: https://leetcode.com/problems/subsets/description.
    题目描述:

    Given a set of distinct integers, nums, return all possible subsets (the power set).

    Note: The solution set must not contain duplicate subsets.

    For example,
    If nums = [1,2,3], a solution is:

    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
      [1,2],
      []
    ]

"""


class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []

        ans = []
        sub = []
        self.backtrace(nums, 0, sub, ans)

        return ans

    def backtrace(self, nums, idx, sub, ans):
        ans.append(sub[:])
        for i in range(idx, len(nums)):
            sub.append(nums[i])
            self.backtrace(nums, i + 1, sub, ans)
            sub.pop()
