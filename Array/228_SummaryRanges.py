# coding: utf8


"""
    题目链接: https://leetcode.com/problems/summary-ranges/description.
    题目描述:

    Given a sorted integer array without duplicates, return the summary of its ranges.

    Example 1:
        Input: [0,1,2,4,5,7]
        Output: ["0->2","4->5","7"]
        Example 2:
        Input: [0,2,3,4,6,8,9]
        Output: ["0","2->4","6","8->9"]
    Credits:
    Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

"""


class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if not nums:
            return []

        summary_ranges = []
        ll = len(nums)
        start = end = nums[0]
        for i in range(1, ll):
            if nums[i] == end + 1:
                end += 1
            else:
                if end != start:
                    summary_ranges.append('{0}->{1}'.format(start, end))
                else:
                    summary_ranges.append('{0}'.format(start))
                start = nums[i]
                end = nums[i]

        if end != start:
            summary_ranges.append('{0}->{1}'.format(start, end))
        else:
            summary_ranges.append('{0}'.format(start))

        return summary_ranges
