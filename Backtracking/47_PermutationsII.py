# coding: utf8


"""
    题目链接: https://leetcode.com/problems/permutations-ii/description.
    题目描述:

    Given a collection of numbers that might contain duplicates, return all possible unique permutations.

    For example,
        [1,1,2] have the following unique permutations:
        [
          [1,1,2],
          [1,2,1],
          [2,1,1]
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
        nums.sort()
        self.backtrace(nums, visited, sub, ans)

        return ans

    def backtrace(self, nums, visited, sub, ans):
        if len(sub) == len(nums):
            ans.append(sub[:])
        else:
            for i in range(len(nums)):
                if not visited[i]:
                    # 前面有重复元素未使用
                    if i > 0 and nums[i] == nums[i - 1] and not visited[i - 1]:
                        continue
                    visited[i] = 1
                    sub.append(nums[i])
                    self.backtrace(nums, visited, sub, ans)
                    sub.pop()
                    visited[i] = 0
