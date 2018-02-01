# coding: utf8


"""
    题目链接: https://leetcode.com/problems/subsets-ii/description.
    题目描述:

    Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

    Note: The solution set must not contain duplicate subsets.

    For example,
    If nums = [1,2,2], a solution is:

    [
      [2],
      [1],
      [1,2,2],
      [2,2],
      [1,2],
      []
    ]

"""


class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []

        ans = []
        sub = []
        visited = [0 for _ in range(len(nums))]
        nums.sort()
        self.backtrace(nums, 0, visited, sub, ans)

        return ans

    def backtrace(self, nums, idx, visited, sub, ans):
        ans.append(sub[:])
        for i in range(idx, len(nums)):
            # 前面有重复元素未使用
            if i > 0 and nums[i] == nums[i - 1] and not visited[i - 1]:
                continue
            visited[i] = 1
            sub.append(nums[i])
            self.backtrace(nums, i + 1, visited, sub, ans)
            sub.pop()
            visited[i] = 0
