# coding: utf8


"""
    题目链接: https://leetcode.com/problems/merge-intervals/description.
    题目描述:

    Given a collection of intervals, merge all overlapping intervals.

    For example,
        Given [1,3],[2,6],[8,10],[15,18],
        return [1,6],[8,10],[15,18].

"""


# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

    def __repr__(self):
        return '(start: {0}, end: {1})'.format(self.start, self.end)


class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals:
            return []

        result = []
        intervals.sort(key=lambda val: val.start)
        first_interval = intervals[0]
        start, end = first_interval.start, first_interval.end
        for interval in intervals:
            if interval.start <= end:
                end = max(end, interval.end)
            else:
                result.append(Interval(start, end))
                start = interval.start
                end = interval.end

        result.append(Interval(start, end))

        return result
