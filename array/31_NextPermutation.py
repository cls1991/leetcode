# coding: utf8


"""
    题目链接: https://leetcode.com/problems/next-permutation/description.
    题目描述:
    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

    If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending
    order).

    The replacement must be in-place, do not allocate extra memory.

    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand
    column.
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1

"""


class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        ll = len(nums)
        target = ll - 1
        lex = True

        for i in range(ll - 2, -1, -1):
            if nums[target] <= nums[i]:
                target -= 1
            else:
                target = i
                lex = False
                break

        if not lex:
            for i in range(ll - 1, target, -1):
                if nums[target] < nums[i]:
                    nums[target], nums[i] = nums[i], nums[target]
                    nums[target + 1:] = sorted(nums[target + 1:])
                    break
        else:
            nums.reverse()
