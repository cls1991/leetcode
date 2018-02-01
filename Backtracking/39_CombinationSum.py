# coding: utf8


"""
    题目链接: https://leetcode.com/problems/combination-sum/description.
    题目描述:

    Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in
    C where the candidate numbers sums to T.

    The same repeated number may be chosen from C unlimited number of times.

    Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
    For example, given candidate set [2, 3, 6, 7] and target 7,
    A solution set is:
    [
      [7],
      [2, 2, 3]
    ]

"""


class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if not candidates:
            return []

        ans = []
        sub = []
        ll = len(candidates)
        # 排序, 避免重复搜索
        candidates.sort()
        self.backtrack(candidates, target, sub, ans, ll, 0)

        return ans

    def backtrack(self, candidates, target, sub, ans, length, idx):
        if target < 0:
            return
        elif target == 0:
            ans.append(sub[:])
        else:
            # 只搜索当前和之后的数
            for i in range(idx, length):
                sub.append(candidates[i])
                self.backtrack(candidates, target - candidates[i], sub, ans, length, i)
                sub.pop()
