# coding: utf8


"""
    题目链接: https://leetcode.com/problems/permutations/description.
    题目描述:

    Given a collection of distinct numbers, return all possible permutations.

    For example,
        [1,2,3] have the following permutations:
        [
          [1,2,3],
          [1,3,2],
          [2,1,3],
          [2,3,1],
          [3,1,2],
          [3,2,1]
        ]

"""


class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []

        ans = []
        sub = []
        visited = [0 for _ in range(len(nums))]
        self.backtrace(nums, visited, sub, ans)

        return ans

    def backtrace(self, nums, visited, sub, ans):
        if len(sub) == len(nums):
            ans.append(sub[:])
        else:
            for i in range(len(nums)):
                if not visited[i]:
                    visited[i] = 1
                    sub.append(nums[i])
                    self.backtrace(nums, visited, sub, ans)
                    sub.pop()
                    visited[i] = 0
